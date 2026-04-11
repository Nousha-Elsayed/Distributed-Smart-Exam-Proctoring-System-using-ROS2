import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import json
import time


class BehaviorAnalysisNode(Node):

    def __init__(self):
        super().__init__('behavior_analysis_node')

        #  Parameters 
        self.declare_parameter('attention_threshold', 3.0)
        self.attention_threshold = self.get_parameter('attention_threshold').value

        #  Internal State 
        self.latest_face   = {}
        self.latest_object = {}
        self.latest_depth  = {}

        self.no_face_since     = None
        self.object_seen_since = None

        #  Subscribers 
        self.create_subscription(String, '/face_data',   self.face_callback,   10)
        self.create_subscription(String, '/object_data', self.object_callback, 10)
        self.create_subscription(String, '/depth_data',  self.depth_callback,  10)

        #  Publisher 
        self.publisher_ = self.create_publisher(String, '/behavior_state', 10)

        # Timer 
        self.timer = self.create_timer(0.5, self.analyze_behavior)

        self.get_logger().info(' Behavior Node is running')

    # CALLBACKS

    def face_callback(self, msg):
        try:
            self.latest_face = json.loads(msg.data)
        except:
            pass

    def object_callback(self, msg):
        try:
            self.latest_object = json.loads(msg.data)
        except:
            pass

    def depth_callback(self, msg):
        try:
            self.latest_depth = json.loads(msg.data)
        except:
            pass

    #  MAIN LOGIC 

    def analyze_behavior(self):
        now = time.time()

        #  FACE 
        face_detected = self.latest_face.get('face_detected', False)
        face_count    = self.latest_face.get('face_count', 0)
        is_looking    = self.latest_face.get('is_looking', True)

        # no face duration
        if not face_detected:
            if self.no_face_since is None:
                self.no_face_since = now
            no_face_duration = now - self.no_face_since
        else:
            self.no_face_since = None
            no_face_duration = 0.0

        #  OBJECT 
        violation_detected = self.latest_object.get('violation_detected', False)
        prohibited_objects = self.latest_object.get('prohibited_objects', [])

        if violation_detected:
            if self.object_seen_since is None:
                self.object_seen_since = now
            object_duration = now - self.object_seen_since
        else:
            self.object_seen_since = None
            object_duration = 0.0

        #  DEPTH 
        unusual_distance = self.latest_depth.get('unusual_distance', False)
        primary_distance = self.latest_depth.get('primary_distance', -1.0)
        lighting         = self.latest_depth.get('lighting', 'unknown')

        #  BEHAVIOR DETECTION 
        behaviors = []

        # No face
        if not face_detected and no_face_duration > self.attention_threshold:
            behaviors.append('no_face')

        # Multiple faces
        if face_count > 1:
            behaviors.append('multiple_faces')

        #  Looking away
        if face_detected and not is_looking:
            behaviors.append('looking_away')

        #  Object usage
        if violation_detected:
            behaviors.append('object_usage')
            for obj in prohibited_objects:
                name = obj.get('class_name', 'unknown').replace(' ', '_')
                behaviors.append(f'prohibited_{name}')

        # Distance issue
        if unusual_distance:
            behaviors.append('unusual_distance')

        #  Lighting issue
        if lighting == 'dark':
            behaviors.append('poor_lighting')

        #  SEVERITY 
        severity = self._calculate_severity(
            behaviors,
            no_face_duration,
            object_duration
        )

        #  OUTPUT 
        state = {
            'behaviors': behaviors,
            'is_suspicious': len(behaviors) > 0,
            'severity': severity,
            'face_detected': face_detected,
            'face_count': face_count,
            'looking': is_looking,
            'no_face_duration': round(no_face_duration, 2),
            'object_duration': round(object_duration, 2),
            'primary_distance': primary_distance,
            'unusual_distance': unusual_distance,
            'lighting': lighting
        }

        msg = String()
        msg.data = json.dumps(state)
        self.publisher_.publish(msg)

        if behaviors:
            self.get_logger().warn(
                f'🚨 Behavior Detected → {behaviors} | severity={severity}'
            )

    #  SEVERITY 

    def _calculate_severity(self, behaviors, no_face_dur, obj_dur):
        score = 0

        if 'no_face' in behaviors:
            score += max(1, int(no_face_dur / 2))

        if 'object_usage' in behaviors:
            score += max(2, int(obj_dur))

        if 'multiple_faces' in behaviors:
            score += 3

        if 'unusual_distance' in behaviors:
            score += 1

        if 'looking_away' in behaviors:
            score += 1   

        if score == 0:
            return 'none'
        elif score <= 2:
            return 'low'
        elif score <= 5:
            return 'medium'
        else:
            return 'high'


def main(args=None):
    rclpy.init(args=args)
    node = BehaviorAnalysisNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
