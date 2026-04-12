#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

from std_msgs.msg import String
from exam_proctoring_interfaces.action import Alert


class AlertActionNode(Node):

    def __init__(self):
        super().__init__('alert_action_node')

        # Publisher
        self.alert_pub = self.create_publisher(String, '/alert_status', 10)

        # Subscriber
        self.sub = self.create_subscription(
            String,
            '/violation_event',
            self.violation_callback,
            10
        )

        # Action Server
        self._action_server = ActionServer(
            self,
            Alert,
            '/alert_action',
            self.execute_callback
        )

        self.get_logger().info("🚨 Alert Action Node READY")

    # ---------------------------
    # violation trigger
    # ---------------------------
    def violation_callback(self, msg):
        self.get_logger().warn(f"Violation received: {msg.data}")

        alert = String()
        alert.data = f"ALERT TRIGGERED: {msg.data}"
        self.alert_pub.publish(alert)

    # ---------------------------
    # ACTION EXECUTION
    # ---------------------------
    async def execute_callback(self, goal_handle):

        self.get_logger().warn(
            f"🚨 ALERT LEVEL: {goal_handle.request.alert_level}"
        )

        # simulate processing
        feedback_msg = Alert.Feedback()
        feedback_msg.status = "Processing alert..."
        goal_handle.publish_feedback(feedback_msg)

        import time
        time.sleep(2)

        # result
        result = Alert.Result()
        result.success = True
        result.response = f"Alert level {goal_handle.request.alert_level} executed"

        self.alert_pub.publish(String(data=result.response))

        goal_handle.succeed()

        return result


def main():
    rclpy.init()
    node = AlertActionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()