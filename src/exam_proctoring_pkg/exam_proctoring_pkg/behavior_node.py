import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import json
import time


class BehaviorAnalysisNode(Node):

    def __init__(self):
        super().__init__('behavior_analysis_node')

        # Parameters
        self.declare_parameter('attention_threshold', 3.0)
        self.attention_threshold = self.get_parameter('attention_threshold').value

        # Internal State
        self.latest_face   = {}
        self.latest_object = {}
        self.latest_depth  = {}

        self.no_face_since     = None
        self.object_seen_since = None

        # Subscribers
        self.create_subscription(String, '/face_data',   self.face_callback,   10)
        self.create_subscription(String, '/object_data', self.object_callback, 10)
        self.create_subscription(String, '/depth_data',  self.depth_callback,  10)

        # Publisher
        self.publisher_ = self.create_publisher(String, '/behavior_state', 10)

        # Timer -  every 0.5 seconds
        self.timer = self.create_timer(0.5, self.analyze_behavior)

        self.get_logger().info('Behavior Analysis Node Started')

    #  Callbacks 

    def face_callback(self, msg):
        try:
            self.latest_face = json.loads(msg.data)
        except Exception:
            pass

    def object_callback(self, msg):
        try:
            self.latest_object = json.loads(msg.data)
        except Exception:
            pass

    def depth_callback(self, msg):
        try:
            self.latest_depth = json.loads(msg.data)
        except Exception:
            pass

    #  Main Logic 

    def analyze_behavior(self):
        now = time.time()

        #  Face data 
        face_detected = self.latest_face.get('face_detected', False)
        face_count    = self.latest_face.get('face_count', 0)
        is_looking    = self.latest_face.get('is_looking', True)

        # Track how long face has been missing
        if not face_detected:
            if self.no_face_since is None:
                self.no_face_since = now
            no_face_duration = now - self.no_face_since
        else:
            self.no_face_since = None
            no_face_duration   = 0.0

        #  Object data 
        violation_detected = self.latest_object.get('violation_detected', False)
        prohibited_objects = self.latest_object.get('prohibited_objects', [])

        # Track how long prohibited object has been visible
        if violation_detected:
            if self.object_seen_since is None:
                self.object_seen_since = now
            object_duration = now - self.object_seen_since
        else:
            self.object_seen_since = None
            object_duration        = 0.0

        #  Depth data 
        unusual_distance = self.latest_depth.get('unusual_distance', False)
        primary_distance = self.latest_depth.get('primary_distance', -1.0)
        lighting         = self.latest_depth.get('lighting', 'unknown')

        #  Behavior Detection 
        behaviors = []

        # No face visible for too long
        if not face_detected and no_face_duration > self.attention_threshold:
            behaviors.append('no_face')

        # More than one face in frame
        if face_count > 1:
            behaviors.append('multiple_faces')

        # Face detected but student not looking at camera
        if face_detected and not is_looking:
            behaviors.append('looking_away')

        # Prohibited object detected
        if violation_detected:
            behaviors.append('object_usage')
            for obj in prohibited_objects:
                name = obj.get('class_name', 'unknown').replace(' ', '_')
                behaviors.append(f'prohibited_{name}')

        # Student too close or too far
        if unusual_distance:
            behaviors.append('unusual_distance')

        # Poor lighting detected
        if lighting == 'dark':
            behaviors.append('poor_lighting')

        #  Severity 
        severity = self._calculate_severity(behaviors, no_face_duration, object_duration)

        #  Publish 
        state = {
            'behaviors':          behaviors,
            'is_suspicious':      len(behaviors) > 0,
            'severity':           severity,
            'face_detected':      face_detected,
            'face_count':         face_count,
            'looking':            is_looking,
            'no_face_duration':   round(no_face_duration, 2),
            'object_duration':    round(object_duration, 2),
            'primary_distance':   primary_distance,
            'unusual_distance':   unusual_distance,
            'lighting':           lighting,
            'prohibited_objects': [o.get('class_name') for o in prohibited_objects],
        }

        out_msg      = String()
        out_msg.data = json.dumps(state)
        self.publisher_.publish(out_msg)

        if behaviors:
            self.get_logger().warn(
                f'Suspicious behavior detected: {behaviors} | severity={severity}'
            )

    #  Severity Scoring 

    def _calculate_severity(self, behaviors, no_face_dur, obj_dur):
        score = 0

        if 'no_face'          in behaviors: score += max(1, int(no_face_dur / 2))
        if 'object_usage'     in behaviors: score += max(2, int(obj_dur))
        if 'multiple_faces'   in behaviors: score += 3
        if 'unusual_distance' in behaviors: score += 1
        if 'looking_away'     in behaviors: score += 1

        if score == 0:   return 'none'
        if score <= 2:   return 'low'
        if score <= 5:   return 'medium'
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
