import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient
from std_msgs.msg import String
import json
import time
from exam_proctoring_interfaces.action import Alert   


class AlertActionNode(Node):

    def __init__(self):
        super().__init__('alert_action_node')

        # Parameters 
        self.declare_parameter('alert_level', 'medium')

        self.alert_level = self.get_parameter('alert_level').value

        self.alert_counter = 0

        # Subscriber 
        self.create_subscription(
            String, '/violation_event', self.violation_callback, 10)

        # Publisher 
        self.pub_status = self.create_publisher(String, '/alert_status', 10)

        # Action Server 
        self._action_server = ActionServer(
            self,
            Alert,
            '/alert_action',
            execute_callback=self.execute_callback
        )

        # Action Client 
        self._action_client = ActionClient(self, Alert, '/alert_action')

        self.get_logger().info(
            f'Alert Node running | level={self.alert_level}'
        )

    # VIOLATION CALLBACK 
    def violation_callback(self, msg: String):
        try:
            event = json.loads(msg.data)
        except json.JSONDecodeError:
            return

        self.alert_counter += 1

        self.execute_alert(event)

        if event.get('severity', 'low') in ['medium', 'high']:
            self.send_goal(event)

    # ALERT LOGIC 
    def execute_alert(self, event: dict):
        violation_id = event.get('violation_id', self.alert_counter)
        severity     = event.get('severity', 'low')
        violations   = event.get('violations', [])
        timestamp    = time.strftime('%H:%M:%S', time.localtime(event.get('timestamp', time.time())))

        alert_msg = (
            f"\n{'='*50}\n"
            f"🚨 ALERT #{violation_id} | {timestamp}\n"
            f"   Severity: {severity.upper()}\n"
        )

        for v in violations:
            alert_msg += f"    [{v.get('rule')}] {v.get('detail')}\n"

        alert_msg += '='*50

        # Print 
        self.get_logger().error(alert_msg)

        # Publish status
        status = {
            'alert_id': violation_id,
            'level': severity,
            'timestamp': timestamp,
            'action_taken': self._get_action_description(severity),
            'violations': violations,
            'total_alerts': self.alert_counter,
        }

        msg = String()
        msg.data = json.dumps(status)
        self.pub_status.publish(msg)

    # ACTION CLIENT 
    def send_goal(self, event):
        goal_msg = Alert.Goal()

        goal_msg.violation_id = event.get('violation_id', 0)
        goal_msg.severity = event.get('severity', 'low')
        goal_msg.description = str(event.get('violations', []))

        self._action_client.wait_for_server()
        self._action_client.send_goal_async(goal_msg)

        self.get_logger().info(f"Sent Action Goal for #{goal_msg.violation_id}")

    # ACTION SERVER 
    async def execute_callback(self, goal_handle):
        self.get_logger().info(f"Executing Action for #{goal_handle.request.violation_id}")

        feedback_msg = Alert.Feedback()

        steps = [
            "Analyzing violation...",
            "Logging event...",
            "Alert..."
        ]

        for i, step in enumerate(steps):
            feedback_msg.current_status = step
            feedback_msg.progress = int((i + 1) / len(steps) * 100)

            goal_handle.publish_feedback(feedback_msg)
            self.get_logger().info(f"{step} ({feedback_msg.progress}%)")

            time.sleep(1)

        goal_handle.succeed()

        result = Alert.Result()
        result.success = True
        result.message = "Alert handled successfully"

        return result

    # ACTION DESCRIPTION 
    def _get_action_description(self, level: str) -> str:
        actions = {
            'none':   'No action',
            'low':    'Logged warning',
            'medium': 'Logged + notified supervisor',
            'high':   'Logged + notified + flagged student',
        }
        return actions.get(level, 'Logged warning')


def main(args=None):
    rclpy.init(args=args)
    node = AlertActionNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
