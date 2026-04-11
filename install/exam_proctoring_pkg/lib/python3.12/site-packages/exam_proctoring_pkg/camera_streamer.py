import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraStreamNode(Node):
    def __init__(self):
        super().__init__('camera_stream_node')

        # Parameters
        self.declare_parameter('camera_source', 0)  # 0 = webcam, or video path
        self.declare_parameter('frame_rate', 30.0)

        self.camera_source = self.get_parameter('camera_source').value
        self.frame_rate = self.get_parameter('frame_rate').value

        self.bridge = CvBridge()

        # Open camera or video file
        self.cap = cv2.VideoCapture(self.camera_source)

        if not self.cap.isOpened():
            self.get_logger().error('Cannot open camera/video ❌')
            return

        # Publisher
        self.publisher = self.create_publisher(Image, '/camera_frames', 10)

        # Timer
        timer_period = 1.0 / self.frame_rate
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.get_logger().info(f'Camera Stream Node Started ✅ | Source: {self.camera_source}')

    def timer_callback(self):
        ret, frame = self.cap.read()

        if not ret:
            self.get_logger().warn('No frame received ⚠️')
            return

        # Convert OpenCV → ROS Image
        msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher.publish(msg)

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = CameraStreamNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()