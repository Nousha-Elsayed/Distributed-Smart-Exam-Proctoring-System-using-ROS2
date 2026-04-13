#!/usr/bin/env python3

import rclpy            #in ros1 #import rospy
from rclpy.node import Node
from sensor_msgs.msg import Image   #from the camera
from std_msgs.msg import String     # to publish json
from cv_bridge import CvBridge      # bridge between opencv and ros2
import cv2
import json

class FaceDetectionNode(Node):          #class inherit from node 
    def __init__(self):
        super().__init__('face_detection_node')         #node constructor # rospy.init_node('face_detection_node')

        # Parameters
        self.declare_parameter('scale_factor', 1.1)         # shrink step 
        self.declare_parameter('min_neighbors', 7)          # face detection accuracy 

        self.scale_factor = self.get_parameter('scale_factor').value
        self.min_neighbors = self.get_parameter('min_neighbors').value      #self.scale_factor = rospy.get_param('~scale_factor', 1.1)

        # Haar Cascades
        self.face_cascade = cv2.CascadeClassifier(
            cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
        )
        self.eye_cascade = cv2.CascadeClassifier(
            cv2.data.haarcascades + 'haarcascade_eye_tree_eyeglasses.xml'
        )

        self.bridge = CvBridge()        # convert it from ROS format to OpenCV format

        # Subscriber                    # rospy.Subscriber('/camera_frames', Image, self.image_callback)
        self.create_subscription(
            Image,
            '/camera_frames',
            self.image_callback,
            10
        )

        # Publisher                     #rospy.Publisher('/face_data', String, queue_size=10)
        self.publisher = self.create_publisher(String, '/face_data', 10)

        self.get_logger().info('Face Detection Node Started')

    def is_looking_at_camera(self, gray_face, face_w, face_h):
        gray_face = cv2.equalizeHist(gray_face)        # Improve contrast
        eyes = self.eye_cascade.detectMultiScale(       # list of the eye bbox 
            gray_face,
            scaleFactor=1.1,
            minNeighbors=1,
            minSize=(int(face_w * 0.1), int(face_h * 0.1))      #to filter noises 
        )

        if len(eyes) == 0:
            return False

        for (ex, ey, ew, eh) in eyes:
            if ey < face_h * 0.70:
                return True

        return False

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        h, w = gray.shape

        faces = self.face_cascade.detectMultiScale(
            gray,
            scaleFactor=self.scale_factor,
            minNeighbors=self.min_neighbors
        )

        face_list = []
        display_frame = frame.copy()        #copy the original frame to draw bbox on

        for (x, y, fw, fh) in faces:
            face_gray = gray[y:y+fh, x:x+fw]
            face_color = display_frame[y:y+fh, x:x+fw]

            # looking detection
            looking = self.is_looking_at_camera(face_gray, fw, fh)

            # center check
            face_center_x = x + fw // 2
            in_center = (w * 0.25) < face_center_x < (w * 0.75)

            # draw rectangle
            box_color = (0, 255, 0) if looking else (0, 0, 255)
            cv2.rectangle(display_frame, (x, y), (x+fw, y+fh), box_color, 2)

            label = 'Looking' if looking else 'Not Looking'
            cv2.putText(display_frame, label,
                        (x, y - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7,
                        box_color, 2)

            # draw eyes
            eyes = self.eye_cascade.detectMultiScale(
                cv2.equalizeHist(face_gray),
                scaleFactor=1.1,
                minNeighbors=1
            )
            for (ex, ey, ew, eh) in eyes:
                cv2.rectangle(face_color,
                              (ex, ey), (ex+ew, ey+eh),
                              (255, 255, 0), 1)

            #   BBOX 
            face_list.append({
                'x1': int(x),
                'y1': int(y),
                'x2': int(x + fw),  
                'y2': int(y + fh),   
                'is_looking': looking,
                'in_center': bool(in_center)
            })

        any_looking = any(f['is_looking'] for f in face_list)       # returns true

        status = f'Faces: {len(face_list)} | Looking: {any_looking}'
        cv2.putText(display_frame, status,
                    (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.8,
                    (255, 255, 255), 2)

        cv2.imshow('Face Detection Node', display_frame)
        cv2.waitKey(1)

        result = {
            'face_count': len(face_list),
            'face_detected': len(face_list) > 0,
            'is_looking': any_looking,
            'faces': face_list
        }

        out_msg = String()
        out_msg.data = json.dumps(result)       # dictionary to a JSON text string
        self.publisher.publish(out_msg)        

        self.get_logger().info(f'Faces: {len(face_list)} | Looking: {any_looking}')     #rospy.loginfo()

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()      #rospy.on_shutdown(my_function) # call the parent class cleanup


def main(args=None):
    rclpy.init(args=args)           #rospy.init_node('name') #__init__
    node = FaceDetectionNode()      

    try:
        rclpy.spin(node)            #rospy.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
