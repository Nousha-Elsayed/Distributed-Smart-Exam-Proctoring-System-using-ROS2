import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import cv2
import json
import numpy as np
import torch

class DepthEstimationNode(Node):
    def __init__(self):
        super().__init__('depth_estimation_node')

        # Parameter
        self.declare_parameter('depth_threshold', 1.5)
        self.depth_threshold = self.get_parameter('depth_threshold').value

        self.bridge = CvBridge()

        # get MiDaS
        self.get_logger().info('Loading MiDaS model... ⏳')
        self.model = torch.hub.load('intel-isl/MiDaS', 'MiDaS_small')
        self.model.eval()

        # Transform
        midas_transforms = torch.hub.load('intel-isl/MiDaS', 'transforms')
        self.transform = midas_transforms.small_transform

        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self.model.to(self.device)

        self.get_logger().info('MiDaS Ready ✅')

        # Subscriber
        self.subscription = self.create_subscription(
            Image,
            '/camera_frames',
            self.image_callback,
            10
        )

        # Publisher
        self.publisher = self.create_publisher(String, '/depth_data', 10)

    def image_callback(self, msg):
        # Convert ROS Image → OpenCV
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        img_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # image preparation 
        input_batch = self.transform(img_rgb).to(self.device)

        # MiDaS
        with torch.no_grad():
            prediction = self.model(input_batch)
            prediction = torch.nn.functional.interpolate(
                prediction.unsqueeze(1),
                size=img_rgb.shape[:2],
                mode='bicubic',
                align_corners=False,
            ).squeeze()

        depth_map = prediction.cpu().numpy()

        # relative depth
        h, w = depth_map.shape
        center_region = depth_map[h//4:3*h//4, w//4:3*w//4]
        avg_depth = float(np.mean(center_region))

        # Normalize 0 : 1
        depth_min = depth_map.min()
        depth_max = depth_map.max()
        normalized_depth = (avg_depth - depth_min) / (depth_max - depth_min + 1e-6)

        #  
        if normalized_depth > 0.65:
            distance_label = 'too_close'
        elif normalized_depth < 0.4:
            distance_label = 'too_far'
        else:
            distance_label = 'normal'

        result = {
            'avg_depth': round(avg_depth, 4),
            'normalized_depth': round(normalized_depth, 4),
            'distance_label': distance_label,
            'too_close': distance_label == 'too_close',
            'too_far': distance_label == 'too_far'
        }

        out_msg = String()
        out_msg.data = json.dumps(result)
        self.publisher.publish(out_msg)

        self.get_logger().info(f'Depth: {distance_label} ({normalized_depth:.2f})')


def main(args=None):
    rclpy.init(args=args)
    node = DepthEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()