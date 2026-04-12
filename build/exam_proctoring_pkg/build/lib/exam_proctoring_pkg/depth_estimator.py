#!/usr/bin/env python3

import json
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import os
import torch

try:
    from depth_anything_v2.dpt import DepthAnythingV2
    DEPTH_AVAILABLE = True
except Exception as e:
    print(f"[ERROR] DepthAnythingV2 import failed: {e}")
    DEPTH_AVAILABLE = False


class DepthEstimationNode(Node):

    def __init__(self):
        super().__init__('depth_estimation_node')

        self.bridge = CvBridge()
        self.model = None

        # -------------------------
        # FIXED MODEL PATH
        # -------------------------
        workspace = "/home/menna/Distributed-Smart-Exam-Proctoring-System-using-ROS2"

        model_path = os.path.join(
            workspace,
            "models",
            "depth_anything",
            "depth_anything_v2_vits.pth"
        )

        self.get_logger().info(f"Using model path: {model_path}")

        # -------------------------
        # LOAD MODEL
        # -------------------------
        if DEPTH_AVAILABLE:
            try:
                self.model = DepthAnythingV2(
                    encoder='vits',
                    features=64,
                    out_channels=[48, 96, 192, 384]
                )

                if not os.path.exists(model_path):
                    raise FileNotFoundError(model_path)

                # 🔥 FIX FOR PYTORCH 2.6 ISSUE
                checkpoint = torch.load(
                    model_path,
                    map_location='cpu',
                    weights_only=False
                )

                # handle different checkpoint formats
                if isinstance(checkpoint, dict):
                    state = checkpoint.get('state_dict') or checkpoint.get('model') or checkpoint
                else:
                    state = checkpoint

                self.model.load_state_dict(state, strict=False)
                self.model.eval()

                self.get_logger().info("✅ Model loaded successfully")

            except Exception as e:
                self.get_logger().error(f"❌ Model load failed: {e}")
                self.model = None

        # -------------------------
        # ROS TOPICS
        # -------------------------
        self.pub_depth_img = self.create_publisher(Image, '/depth_data', 10)
        self.pub_metrics = self.create_publisher(String, '/object_depth', 10)

        self.sub = self.create_subscription(
            Image,
            '/camera_frames',
            self.callback,
            10
        )

        cv2.namedWindow("Depth Map", cv2.WINDOW_NORMAL)
        self.get_logger().info("🚀 Depth Node READY")

    # -------------------------
    # CALLBACK
    # -------------------------
    def callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            if self.model is not None:
                inp = cv2.resize(frame, (384, 384))
                depth_small = self.model.infer_image(inp)

                depth = cv2.resize(
                    depth_small,
                    (frame.shape[1], frame.shape[0])
                )
            else:
                h, w = frame.shape[:2]
                depth = np.random.rand(h, w).astype(np.float32)

            dmin, dmax = float(depth.min()), float(depth.max())

            depth_vis = ((depth - dmin) / (dmax - dmin + 1e-6) * 255).astype(np.uint8)
            depth_color = cv2.applyColorMap(depth_vis, cv2.COLORMAP_INFERNO)

            cv2.imshow("Depth Map", depth_color)
            cv2.waitKey(1)

            # publish image
            img_msg = self.bridge.cv2_to_imgmsg(depth_vis, encoding='mono8')
            img_msg.header.stamp = self.get_clock().now().to_msg()
            self.pub_depth_img.publish(img_msg)

            # metrics
            h, w = depth.shape
            cx, cy = w // 2, h // 2

            crop = depth[max(0, cy-30):min(h, cy+30),
                         max(0, cx-30):min(w, cx+30)]

            msg = String()
            msg.data = json.dumps({
                "center_depth": float(np.mean(crop)) if crop.size else 0.0,
                "min": dmin,
                "max": dmax
            })

            self.pub_metrics.publish(msg)

        except Exception as e:
            self.get_logger().error(f"Callback error: {e}")


def main():
    rclpy.init()
    node = DepthEstimationNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()