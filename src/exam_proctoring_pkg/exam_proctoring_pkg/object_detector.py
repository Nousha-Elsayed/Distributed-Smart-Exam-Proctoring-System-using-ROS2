#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from std_msgs.msg import String

from cv_bridge import CvBridge
import cv2
import json
import time
import os

from ultralytics import YOLO
from ament_index_python.packages import get_package_share_directory


class ObjectDetectionNode(Node):

    def __init__(self):
        super().__init__('object_detection_node')

        # ===== PARAMETERS =====
        self.declare_parameter('confidence_threshold', 0.3)
        self.conf_threshold = self.get_parameter('confidence_threshold').value

        # ===== PATH TO MODEL (ROS2 WAY) =====
        pkg_share = get_package_share_directory('exam_proctoring_pkg')
        yolo_path = os.path.join(pkg_share, 'models', 'yolo', 'yolov8n.pt')

        self.get_logger().info(f"Loading YOLO model from: {yolo_path}")

        # ===== YOLO MODEL =====
        self.model = YOLO(yolo_path)

        # ===== CV BRIDGE =====
        self.bridge = CvBridge()

        # ===== SUBSCRIBER =====
        self.subscription = self.create_subscription(
            Image,
            '/camera_frames',
            self.image_callback,
            10
        )

        # ===== PUBLISHER =====
        self.publisher = self.create_publisher(
            String,
            '/object_data',
            10
        )

        # ===== FPS =====
        self.prev_time = time.time()

        # ===== WINDOW =====
        cv2.namedWindow("Object Detection", cv2.WINDOW_NORMAL)

        self.get_logger().info("🚀 Object Detection Node Started")

    def image_callback(self, msg):

        # ===== CONVERT IMAGE =====
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"CV Bridge Error: {e}")
            return

        # ===== YOLO INFERENCE =====
        results = self.model(frame, verbose=False)[0]

        detected_objects = []

        # ===== DRAW RESULTS =====
        for box in results.boxes:
            conf = float(box.conf[0])

            if conf < self.conf_threshold:
                continue

            cls_id = int(box.cls[0])
            label = self.model.names[cls_id]

            x1, y1, x2, y2 = map(int, box.xyxy[0])

            # draw box
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(frame, f"{label} {conf:.2f}",
                        (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.6,
                        (0, 255, 0),
                        2)

            # filter exam objects
            if label in ["cell phone", "book"]:
                detected_objects.append({
                    "label": label,
                    "confidence": conf,
                    "bbox": [x1, y1, x2, y2]
                })

        # ===== FPS =====
        current_time = time.time()
        fps = 1.0 / (current_time - self.prev_time)
        self.prev_time = current_time

        cv2.putText(frame, f"FPS: {fps:.2f}", (20, 40),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

        cv2.putText(frame, "YOLO Object Detection", (20, 80),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 0), 2)

        # ===== SHOW WINDOW =====
        cv2.imshow("Object Detection", frame)
        cv2.waitKey(1)

        # ===== PUBLISH =====
        msg_out = String()
        msg_out.data = json.dumps({
            "objects": detected_objects,
            "fps": fps
        })

        self.publisher.publish(msg_out)

        self.get_logger().info(f"Detected: {len(detected_objects)} objects")


def main(args=None):
    rclpy.init(args=args)

    node = ObjectDetectionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()