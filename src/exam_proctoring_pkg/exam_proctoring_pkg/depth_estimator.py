#!/usr/bin/env python3

import json
import numpy as np
import rclpy
from rclpy.node import Node         #import rospy
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import os           #build file paths and check if files exist
import torch

from ament_index_python.packages import get_package_share_directory     #rospkg.RosPack().get_path('package_name')
import os

# DepthAnything import
try:
    from depth_anything_v2.dpt import DepthAnythingV2
    DEPTH_AVAILABLE = True
except Exception as e:
    print(f"[ERROR] DepthAnythingV2 import failed: {e}")
    DEPTH_AVAILABLE = False


class DepthEstimationNode(Node):

    def __init__(self):
        super().__init__('depth_estimation_node')       #rospy.init_node('depth_estimation_node')

        self.bridge = CvBridge()        #CvBridge instance
        self.model = None

        pkg_share = get_package_share_directory('exam_proctoring_pkg')

        model_path = os.path.join(
            pkg_share,
            "models",
            "depth_anything",
            "depth_anything_v2_vits.pth"
        )

        self.get_logger().info(f"Model path: {model_path}")       #rospy.loginfo(...)

        if not os.path.exists(model_path):
            self.get_logger().error(" Model not found in install space. Did you run colcon build?")
            model_path = None
        # LOAD MODEL
        if DEPTH_AVAILABLE and model_path is not None:
            try:
                self.model = DepthAnythingV2(
                    encoder='vits',
                    features=64,                        #the internal feature dimension size
                    out_channels=[48, 96, 192, 384]     #the output channels at each decoder layer
                )

                checkpoint = torch.load(        #reads the .pth
                    model_path,
                    map_location='cpu'
                )

                if isinstance(checkpoint, dict):        #handle different pytorch models
                    state_dict = (
                        checkpoint.get('state_dict') or
                        checkpoint.get('model') or
                        checkpoint
                    )
                else:
                    state_dict = checkpoint

                self.model.load_state_dict(state_dict, strict=False)
                self.model.eval()     #sets the model to evaluation mode

                self.get_logger().info(" Depth model loaded successfully")

            except Exception as e:
                self.get_logger().error(f" Model loading failed: {e}")
                self.model = None

        # ROS IO
        self.pub_depth_img = self.create_publisher(Image, '/depth_data', 10)    #rospy.publisher('/depth_data', Image, queue_size=10)
        self.pub_metrics = self.create_publisher(String, '/object_depth', 10)

        self.create_subscription(           #rospy.Subscriber('/camera_frames', Image, self.callback)
            Image,
            '/camera_frames',
            self.callback,
            10
        )

        try:
            cv2.namedWindow("Depth Map", cv2.WINDOW_NORMAL) 
        except:
            pass

        self.get_logger().info("Depth Estimation Node Ready")

    # =========================================================
    def callback(self, msg):

        try:
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            # DEPTH INFERENCE
            if self.model is not None:
                inp = cv2.resize(frame, (384, 384))
                depth_small = self.model.infer_image(inp)

                depth = cv2.resize(
                    depth_small,
                    (frame.shape[1], frame.shape[0]) # width,height
                )
            else:
                h, w = frame.shape[:2]
                depth = np.random.rand(h, w).astype(np.float32)

            
            # NORMALIZATION
            dmin, dmax = float(depth.min()), float(depth.max())

            depth_vis = ((depth - dmin) / (dmax - dmin + 1e-6) * 255).astype(np.uint8)

            depth_color = cv2.applyColorMap(depth_vis, cv2.COLORMAP_INFERNO)

            try:
                cv2.imshow("Depth Map", depth_color)
                cv2.waitKey(1)
            except:
                pass

            # PUBLISH IMAGE
            img_msg = self.bridge.cv2_to_imgmsg(depth_vis, encoding='mono8')
            img_msg.header.stamp = self.get_clock().now().to_msg()
            self.pub_depth_img.publish(img_msg)

            # CENTER DEPTH
            h, w = depth.shape
            cx, cy = w // 2, h // 2

            crop = depth[
                max(0, cy-30):min(h, cy+30),
                max(0, cx-30):min(w, cx+30)
            ]

            center_depth = float(np.mean(crop)) if crop.size else 0.0

            self.pub_metrics.publish(String(data=json.dumps({
                "center_depth": center_depth,
                "min_depth": dmin,
                "max_depth": dmax
            })))

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