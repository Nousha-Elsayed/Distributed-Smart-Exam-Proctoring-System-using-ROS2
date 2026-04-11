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

        # Haar Cascade
        self.face_cascade = cv2.CascadeClassifier(
            cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
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

    def image_callback(self, msg):
        # Convert ROS Image → OpenCV
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Detect faces
        faces = self.face_cascade.detectMultiScale(
            gray,
            scaleFactor=self.scale_factor,
            minNeighbors=self.min_neighbors
        )

        # Build output data
        face_list = []
        for (x, y, w, h) in faces:
            face_list.append({
                'x': int(x),
                'y': int(y),
                'width': int(w),
                'height': int(h)
            })

        result = {
            'face_count': len(face_list),
            'faces': face_list,
            'face_detected': len(face_list) > 0
        }

        # Publish
        out_msg = String()
        out_msg.data = json.dumps(result)
        self.publisher.publish(out_msg)

        self.get_logger().info(f'Faces detected: {len(face_list)}')


def main(args=None):
    rclpy.init(args=args)
    node = FaceDetectionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()