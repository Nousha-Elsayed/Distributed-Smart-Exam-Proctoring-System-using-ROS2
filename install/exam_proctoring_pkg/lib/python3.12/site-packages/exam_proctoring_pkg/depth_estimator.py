import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
import torch

class DepthEstimation(Node):
    def __init__(self):
        super().__init__('depth_estimation_node')

        # Parameter
        self.declare_parameter('depth_threshold', 1.5)
        self.depth_threshold = self.get_parameter('depth_threshold').value

        self.bridge = CvBridge()

        # Load MiDaS
        self.get_logger().info('Loading MiDaS model... ⏳')
        self.model = torch.hub.load('intel-isl/MiDaS', 'MiDaS_small',
                                     trust_repo=True)
        self.model.eval()

        midas_transforms = torch.hub.load('intel-isl/MiDaS', 'transforms',
                                           trust_repo=True)
        self.transform = midas_transforms.small_transform

        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self.model.to(self.device)
        self.get_logger().info(f'MiDaS Ready ✅ | Device: {self.device}')

        # Subscriber
        self.subscription = self.create_subscription(
            Image,
            '/camera_frames',
            self.image_callback,
            10
        )

        # Publisher → full depth map as image
        self.publisher = self.create_publisher(Image, '/depth_data', 10)

        self.get_logger().info('Depth Estimation Node Started ✅')

    def image_callback(self, msg):
        # Convert ROS Image → OpenCV
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        img_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Run MiDaS
        input_batch = self.transform(img_rgb).to(self.device)
        with torch.no_grad():
            prediction = self.model(input_batch)
            prediction = torch.nn.functional.interpolate(
                prediction.unsqueeze(1),
                size=img_rgb.shape[:2],
                mode='bicubic',
                align_corners=False,
            ).squeeze()

        depth_map = prediction.cpu().numpy()

        # Normalize to 0-255 for publishing & display
        depth_min = depth_map.min()
        depth_max = depth_map.max()
        depth_normalized = (
            (depth_map - depth_min) / (depth_max - depth_min + 1e-6) * 255
        ).astype(np.uint8)

        # Apply colormap → heatmap (COLORMAP_INFERNO looks best)
        depth_colormap = cv2.applyColorMap(depth_normalized, cv2.COLORMAP_INFERNO)

        # Show in CV window
        combined = np.hstack([frame, depth_colormap])
        cv2.putText(combined, 'Camera', (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255,255,255), 2)
        cv2.putText(combined, 'Depth Map', (frame.shape[1] + 10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255,255,255), 2)
        cv2.imshow('Depth Estimation Node', combined)
        cv2.waitKey(1)

        # Publish full depth map as ROS Image
        depth_msg = self.bridge.cv2_to_imgmsg(depth_normalized, encoding='mono8')
        depth_msg.header.stamp = self.get_clock().now().to_msg()
        self.publisher.publish(depth_msg)

        self.get_logger().info('Depth map published ✅')

    def destroy_node(self):
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = DepthEstimation()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()