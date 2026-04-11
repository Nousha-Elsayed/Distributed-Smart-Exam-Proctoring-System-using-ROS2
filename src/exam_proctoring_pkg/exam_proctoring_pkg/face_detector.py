import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import json

class FaceDetectionNode(Node):
    def __init__(self):
        super().__init__('face_detection_node')

        # Parameters
        self.declare_parameter('scale_factor', 1.1)
        self.declare_parameter('min_neighbors', 5)

        self.scale_factor = self.get_parameter('scale_factor').value
        self.min_neighbors = self.get_parameter('min_neighbors').value

        # Haar Cascade for face and eyes
        self.face_cascade = cv2.CascadeClassifier(
            cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
        )
        self.eye_cascade = cv2.CascadeClassifier(
            cv2.data.haarcascades + 'haarcascade_eye.xml'
        )

        self.bridge = CvBridge()

        # Subscriber
        self.subscription = self.create_subscription(
            Image,
            '/camera_frames',
            self.image_callback,
            10
        )

        # Publisher
        self.publisher = self.create_publisher(String, '/face_data', 10)

        self.get_logger().info('Face Detection Node Started ✅')

    def is_looking_at_camera(self, gray_face, face_w, face_h):
        """
        Detects eyes inside the face region.
        If eyes are visible → student is looking ✅
        If not → student is looking away ❌
        """
        eyes = self.eye_cascade.detectMultiScale(
            gray_face,
            scaleFactor=1.1,
            minNeighbors=3
        )

        if len(eyes) < 1:
            return False  # Not looking

        # Make sure eyes are in the upper half of the face
        for (ex, ey, ew, eh) in eyes:
            if ey < face_h * 0.6:
                return True

        return False

    def image_callback(self, msg):
        # Convert ROS Image → OpenCV
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        h, w = gray.shape

        # Detect faces
        faces = self.face_cascade.detectMultiScale(
            gray,
            scaleFactor=self.scale_factor,
            minNeighbors=self.min_neighbors
        )

        face_list = []
        for (x, y, fw, fh) in faces:
            # Crop face region only
            face_gray = gray[y:y+fh, x:x+fw]

            # Check if student is looking
            looking = self.is_looking_at_camera(face_gray, fw, fh)

            # Check if face is centered in frame
            face_center_x = x + fw // 2
            in_center = (w * 0.25) < face_center_x < (w * 0.75)

            face_list.append({
                'x': int(x),
                'y': int(y),
                'width': int(fw),
                'height': int(fh),
                'is_looking': looking,
                'in_center': bool(in_center)
            })

        # Final decision
        any_looking = any(f['is_looking'] for f in face_list)

        result = {
            'face_count': len(face_list),
            'face_detected': len(face_list) > 0,
            'is_looking': any_looking,
            'faces': face_list
        }

        out_msg = String()
        out_msg.data = json.dumps(result)
        self.publisher.publish(out_msg)

        self.get_logger().info(
            f'Faces: {len(face_list)} | Looking: {any_looking}'
        )


def main(args=None):
    rclpy.init(args=args)
    node = FaceDetectionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()