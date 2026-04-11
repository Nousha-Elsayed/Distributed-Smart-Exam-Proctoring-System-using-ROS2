import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from std_srvs.srv import Trigger
import json
import time


class RuleEvaluationNode(Node):

    def __init__(self):
        super().__init__('rule_evaluation_node')

        # Parameters
        self.declare_parameter('no_face_violation_sec', 3.0)
        self.declare_parameter('object_violation_sec', 0.5)
        self.declare_parameter('multi_face_violation', True)
        self.declare_parameter('unusual_dist_violation', False)
        self.declare_parameter('looking_away_violation', True)

        self.no_face_limit = self.get_parameter('no_face_violation_sec').value
        self.object_limit = self.get_parameter('object_violation_sec').value
        self.multi_face_rule = self.get_parameter('multi_face_violation').value
        self.dist_rule = self.get_parameter('unusual_dist_violation').value
        self.looking_away_rule = self.get_parameter('looking_away_violation').value

        # State
        self.latest_behavior = {}
        self.violation_counter = 0
        self.last_violation_time = 0.0
        self.violation_cooldown = 2.0  # seconds to prevent spamming

        # Subscriber
        self.create_subscription(
            String, '/behavior_state', self.behavior_callback, 10)

        # Publisher
        self.pub_violation = self.create_publisher(
            String, '/violation_event', 10)

        # Service
        self.create_service(
            Trigger, '/check_violation', self.check_violation_service)

        self.get_logger().info('Rule Evaluation Node started')

    # ---------- Callback ----------

    def behavior_callback(self, msg: String):
        try:
            self.latest_behavior = json.loads(msg.data)
        except json.JSONDecodeError:
            return

        violations = self.evaluate_rules(self.latest_behavior)

        # Debounce logic
        current_time = time.time()
        if violations and (current_time - self.last_violation_time > self.violation_cooldown):
            self.last_violation_time = current_time

            self.violation_counter += 1

            event = {
                'violation_id': self.violation_counter,
                'timestamp': current_time,
                'violations': violations,
                'severity': self.latest_behavior.get('severity', 'low'),
                'behaviors': self.latest_behavior.get('behaviors', []),
                'prohibited_objs': self.latest_behavior.get('prohibited_objects', []),
            }

            out_msg = String()
            out_msg.data = json.dumps(event)
            self.pub_violation.publish(out_msg)

            self.get_logger().error(
                f'Violation #{self.violation_counter} | rules: {[v["rule"] for v in violations]}'
            )

    #  Rule Engine 

    def evaluate_rules(self, behavior: dict) -> list:
        violations = []

        # Rule 1: No face detected for too long
        no_face_dur = behavior.get('no_face_duration', 0.0)
        if not behavior.get('face_detected', True) and no_face_dur >= self.no_face_limit:
            violations.append({
                'rule': 'NO_FACE_TIMEOUT',
                'detail': f'No face detected for {no_face_dur:.1f}s',
                'level': 'high'
            })

        # Rule 2: Prohibited object
        objs = behavior.get('prohibited_objects', [])
        obj_dur = behavior.get('object_duration', 0.0)
        if len(objs) > 0 and obj_dur >= self.object_limit:
            violations.append({
                'rule': 'PROHIBITED_OBJECT',
                'detail': f'Prohibited item detected: {objs}',
                'level': 'high'
            })

        # Rule 3: Multiple faces
        if self.multi_face_rule and behavior.get('face_count', 0) > 1:
            violations.append({
                'rule': 'MULTIPLE_FACES',
                'detail': f"{behavior.get('face_count')} faces detected",
                'level': 'medium'
            })

        # Rule 4: Unusual distance
        if self.dist_rule and behavior.get('unusual_distance', False):
            violations.append({
                'rule': 'UNUSUAL_DISTANCE',
                'detail': 'Abnormal distance from camera',
                'level': 'low'
            })

        # Rule 5: Looking away
        if self.looking_away_rule and behavior.get('looking') is False:
            violations.append({
                'rule': 'LOOKING_AWAY',
                'detail': 'Student not looking at screen',
                'level': 'medium'
            })

        return violations

    #  Service 

    def check_violation_service(self, request, response):
        violations = self.evaluate_rules(self.latest_behavior)

        response.success = len(violations) > 0
        response.message = json.dumps(violations) if violations else 'No violations'

        return response


def main(args=None):
    rclpy.init(args=args)
    node = RuleEvaluationNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
