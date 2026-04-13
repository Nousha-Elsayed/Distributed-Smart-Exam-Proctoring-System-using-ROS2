#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import json
import numpy as np
import time

try:
    from ultralytics import YOLO
    YOLO_AVAILABLE = True
except ImportError:
    YOLO_AVAILABLE = False
    print("[WARNING] Ultralytics YOLO not installed")


class ObjectDetectionNode(Node):
    def __init__(self):
        super().__init__('object_detection_node')

        # Parameters
        self.declare_parameter('confidence_threshold', 0.5)
        self.declare_parameter('model_path', 'yolov8n.pt')
        self.declare_parameter('device', 'cpu')
        self.declare_parameter('frame_skip', 4)
        self.declare_parameter('prohibited_classes', 'phone,book,laptop,tablet')

        self.confidence_threshold = self.get_parameter('confidence_threshold').value
        model_path = self.get_parameter('model_path').value
        self.device = self.get_parameter('device').value
        self.frame_skip = self.get_parameter('frame_skip').value

        prohibited_str = self.get_parameter('prohibited_classes').value
        self.prohibited_classes = [c.strip() for c in prohibited_str.split(',')]

        self.get_logger().info('=' * 50)
        self.get_logger().info('Object Detection Node Initializing')
        self.get_logger().info(f'Confidence threshold: {self.confidence_threshold}')
        self.get_logger().info(f'Prohibited classes: {self.prohibited_classes}')
        self.get_logger().info(f'Device: {self.device}')
        self.get_logger().info('=' * 50)

        # Load YOLO
        self.model = None
        if YOLO_AVAILABLE:
            try:
                self.model = YOLO(model_path)
                self.model.to(self.device)
                self.get_logger().info(f'YOLO model loaded from {model_path}')
            except Exception as e:
                self.get_logger().error(f'Failed to load YOLO model: {e}')
        else:
            self.get_logger().warn('YOLO not available - demo mode')

        # COCO classes
        self.coco_classes = {
            63: 'laptop', 67: 'cell phone', 73: 'book',
            26: 'handbag', 24: 'backpack', 39: 'bottle'
        }

        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image, '/camera_frames', self.image_callback, 10
        )

        self.publisher = self.create_publisher(
            String, '/object_data', 10
        )

        self.frame_count = 0
        self.processing_times = []

        self.get_logger().info('🚀 Object Detection Node READY')

    def image_callback(self, msg):
        self.frame_count += 1

        # Frame skipping
        if self.frame_count % (self.frame_skip + 1) != 0:
            return

        start_time = time.time()

        try:
            frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            h, w = frame.shape[:2]

            result = {
                'violation_detected': False,
                'prohibited_objects': [],
                'object_count': 0,
                'objects': [],
                'timestamp': self.get_clock().now().to_msg().sec
            }

            if self.model is not None:

                # 🔥 KEY FIX: use smaller image
                small_frame = cv2.resize(frame, (256, 192))

                # scale factors
                scale_x = w / 256
                scale_y = h / 192

                results = self.model(
                    small_frame,
                    conf=self.confidence_threshold,
                    verbose=False
                )

                for r in results:
                    if r.boxes is None:
                        continue

                    for box in r.boxes:
                        class_id = int(box.cls[0])
                        confidence = float(box.conf[0])
                        class_name = self.coco_classes.get(class_id, 'unknown')

                        x1, y1, x2, y2 = box.xyxy[0].tolist()

                        # 🔥 scale back to original size
                        x1 *= scale_x
                        x2 *= scale_x
                        y1 *= scale_y
                        y2 *= scale_y

                        width = x2 - x1
                        height = y2 - y1

                        obj = {
                            'class_id': class_id,
                            'class_name': class_name,
                            'confidence': confidence,
                            'bbox': {
                                'x': int(x1),
                                'y': int(y1),
                                'width': int(width),
                                'height': int(height)
                            }
                        }

                        result['objects'].append(obj)
                        result['object_count'] += 1

                        if class_name in self.prohibited_classes:
                            result['violation_detected'] = True
                            result['prohibited_objects'].append(obj)

                            self.get_logger().info(
                                f'🚨 {class_name} detected ({confidence:.2f})'
                            )

            # Publish
            msg_out = String()
            msg_out.data = json.dumps(result)
            self.publisher.publish(msg_out)

            # FPS
            processing_time = time.time() - start_time
            self.processing_times.append(processing_time)

            if len(self.processing_times) > 30:
                self.processing_times.pop(0)

            avg_time = sum(self.processing_times) / len(self.processing_times)
            fps = 1.0 / avg_time if avg_time > 0 else 0

            if fps < 4.8 and self.frame_count > 30:
                self.get_logger().warn(f'FPS low: {fps:.2f}')

        except Exception as e:
            self.get_logger().error(f'Error: {e}')


def main():
    rclpy.init()
    node = ObjectDetectionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()