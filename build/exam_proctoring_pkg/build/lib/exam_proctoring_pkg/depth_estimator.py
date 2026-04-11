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

MODEL_CONFIGS = {
    'Small': {'encoder': 'vits', 'features': 64,  'out_channels': [48, 96, 192, 384]},
    'Base':  {'encoder': 'vitb', 'features': 128, 'out_channels': [96, 192, 384, 768]},
    'Large': {'encoder': 'vitl', 'features': 256, 'out_channels': [256, 512, 1024, 1024]},
}

class DepthEstimationNode(Node):

    def __init__(self):
        super().__init__('depth_estimation_node')

        self.declare_parameter('model_size', 'Small')
        self.declare_parameter('model_path', '')

        model_size = self.get_parameter('model_size').value
        model_path = self.get_parameter('model_path').value

        self.bridge = CvBridge()
        self.model = None

        if DEPTH_AVAILABLE:
            try:
                cfg = MODEL_CONFIGS.get(model_size, MODEL_CONFIGS['Small'])
                self.model = DepthAnythingV2(**cfg)

                if model_path == "":
                    model_path = os.path.join(
                        os.path.dirname(__file__),
                        "depth_anything_v2_vits.pth"
                    )

                checkpoint = torch.load(model_path, map_location='cpu')
                state = checkpoint.get('state_dict') or checkpoint.get('model') or checkpoint
                self.model.load_state_dict(state, strict=False)
                self.model.eval()
                self.get_logger().info("✅ Model loaded")

            except Exception as e:
                self.get_logger().error(f"❌ Load failed: {e}")

        # Publisher → full depth map as Image
        self.pub_depth_img = self.create_publisher(Image, '/depth_data', 10)

        # Publisher → depth metrics as JSON
        self.pub_metrics = self.create_publisher(String, '/object_depth', 10)

        self.sub = self.create_subscription(
            Image, '/camera_frames', self.callback, 10)

        cv2.namedWindow("Depth Map", cv2.WINDOW_NORMAL)
        self.get_logger().info("🚀 Depth Estimation Node READY")

    def callback(self, msg: Image):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            if self.model is not None:
                inp = cv2.resize(frame, (384, 384))
                depth_small = self.model.infer_image(inp)
                depth = cv2.resize(depth_small,
                                   (frame.shape[1], frame.shape[0]),
                                   interpolation=cv2.INTER_CUBIC)
            else:
                h, w = frame.shape[:2]
                depth = np.tile(
                    np.linspace(0, 1, h).reshape(h, 1), (1, w)
                ).astype(np.float32) * 10

            dmin, dmax = float(np.min(depth)), float(np.max(depth))
            if abs(dmax - dmin) < 1e-6:
                return

            # Normalize & colormap
            depth_vis = ((depth - dmin) / (dmax - dmin) * 255).astype(np.uint8)
            depth_color = cv2.applyColorMap(depth_vis, cv2.COLORMAP_INFERNO)

            # Show depth map only
            cv2.imshow("Depth Map", depth_color)
            cv2.waitKey(1)

            # Publish depth map as ROS Image
            depth_msg = self.bridge.cv2_to_imgmsg(depth_vis, encoding='mono8')
            depth_msg.header.stamp = self.get_clock().now().to_msg()
            self.pub_depth_img.publish(depth_msg)

            # Publish metrics as JSON
            h, w = depth.shape
            cx, cy = w // 2, h // 2
            crop = depth[max(0,cy-30):min(h,cy+30), max(0,cx-30):min(w,cx+30)]

            metrics = String()
            metrics.data = json.dumps({
                "center_depth": float(np.mean(crop)) if crop.size > 0 else 0.0,
                "min_depth": dmin,
                "max_depth": dmax,
            })
            self.pub_metrics.publish(metrics)

        except Exception as e:
            self.get_logger().error(f"Callback error: {e}")

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = DepthEstimationNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()

if __name__ == "__main__":
    main()