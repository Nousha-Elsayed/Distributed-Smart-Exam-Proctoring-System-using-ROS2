#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import Image


# NODE CLASS
class SystemMonitorNode(Node):

    def __init__(self):
        super().__init__('system_monitor_node')

        # SUBSCRIBERS (listen to all topics)
        self.create_subscription(Image, '/camera_frames', self.camera_cb, 10)
        self.create_subscription(String, '/face_data', self.face_cb, 10)
        self.create_subscription(String, '/object_data', self.object_cb, 10)
        self.create_subscription(Image, '/depth_data', self.depth_cb, 10)
        self.create_subscription(String, '/behavior_state', self.behavior_cb, 10)
        self.create_subscription(String, '/violation_event', self.violation_cb, 10)
        self.create_subscription(String, '/alert_status', self.alert_cb, 10)

        # COUNTERS (system statistics)
        self.frames = 0
        self.faces = 0
        self.objects = 0
        self.violations = 0

        # TIMER (runs every 2 seconds)
        self.create_timer(2.0, self.print_status)

        self.get_logger().info("📊 System Monitor Node Started")


    # CALLBACK FUNCTIONS

    # Called whenever a new camera frame is received
    def camera_cb(self, msg):
        self.frames += 1

    # Called when face detection publishes data
    def face_cb(self, msg):
        self.faces += 1

    # Called when object detection publishes data
    def object_cb(self, msg):
        self.objects += 1

    # Depth data received (not used, just monitored)
    def depth_cb(self, msg):
        pass

    # Behavior state received
    def behavior_cb(self, msg):
        pass

    # Called when a violation is detected
    def violation_cb(self, msg):
        self.violations += 1

    # Called when an alert is triggered
    def alert_cb(self, msg):
        self.get_logger().warn(f"🚨 ALERT RECEIVED: {msg.data}")


    def print_status(self):
        self.get_logger().info(
            f"[SYSTEM STATUS] Frames: {self.frames} | Faces: {self.faces} | Objects: {self.objects} | Violations: {self.violations}"
        )


def main():
    rclpy.init()

    node = SystemMonitorNode()

    try:
        rclpy.spin(node)   # keeps node running
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()