import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import json
import time
import numpy as np


class BehaviorAnalysisNode(Node):

    def __init__(self):
        super().__init__('behavior_analysis_node')

        self.declare_parameter('attention_threshold', 3.0)
        self.attention_threshold = self.get_parameter('attention_threshold').value

        self.latest_face = {}
        self.latest_object = {}
        self.depth_map = None

        self.no_face_since = None

        self.bridge = CvBridge()

        # Subscribers
        self.create_subscription(String, '/face_data', self.face_callback, 10)
        self.create_subscription(String, '/object_data', self.object_callback, 10)
        self.create_subscription(Image, '/depth_data', self.depth_callback, 10)

        # Publisher
        self.publisher = self.create_publisher(String, '/behavior_state', 10)

        self.timer = self.create_timer(0.5, self.analyze)

        self.get_logger().info("Behavior Node started")

    #  Callbacks 

    def face_callback(self, msg):
        try:
            self.latest_face = json.loads(msg.data)
        except:
            self.get_logger().warn("Invalid face_data")

    def object_callback(self, msg):
        try:
            self.latest_object = json.loads(msg.data)
        except:
            self.get_logger().warn("Invalid object_data")

    def depth_callback(self, msg):
        try:
            self.depth_map = self.bridge.imgmsg_to_cv2(msg)
        except:
            self.depth_map = None
            self.get_logger().warn("Depth conversion failed")

    #  Main Logic 

    def analyze(self):
        now = time.time()
        behaviors = []

        #  Face 
        face_detected = self.latest_face.get('face_detected', False)
        face_count = self.latest_face.get('face_count', 0)
        is_looking = self.latest_face.get('is_looking', True)

        # Get bbox
        bbox = None
        faces = self.latest_face.get("faces", [])

        if len(faces) > 0:
            f = faces[0]
            bbox = [f["x1"], f["y1"], f["x2"], f["y2"]]

        # No face logic
        if not face_detected:
            if self.no_face_since is None:
                self.no_face_since = now
            no_face_duration = now - self.no_face_since
        else:
            self.no_face_since = None
            no_face_duration = 0.0

        if not face_detected and no_face_duration > self.attention_threshold:
            behaviors.append("no_face")

        if face_count > 1:
            behaviors.append("multiple_faces")

        if face_detected and not is_looking:
            behaviors.append("looking_away")

        #  Object 
        violation_detected = self.latest_object.get('violation_detected', False)
        prohibited_objects = self.latest_object.get('prohibited_objects', [])

        if violation_detected:
            behaviors.append("object_usage")

            for obj in prohibited_objects:
                name = obj.get("class_name", "unknown").replace(" ", "_")
                behaviors.append(f"prohibited_{name}")

        #  Depth 
        primary_distance = -1.0
        unusual_distance = False

        if self.depth_map is None:
            self.get_logger().warn("No depth map received")

        if self.depth_map is not None and bbox is not None:
            x1, y1, x2, y2 = bbox

            h, w = self.depth_map.shape[:2]

            # Clamp bbox
            x1 = max(0, min(w - 1, int(x1)))
            x2 = max(0, min(w, int(x2)))
            y1 = max(0, min(h - 1, int(y1)))
            y2 = max(0, min(h, int(y2)))

            crop = self.depth_map[y1:y2, x1:x2]

            if crop.size > 0:
                primary_distance = float(np.mean(crop))

                #   THRESHOLDS (0–255)
                unusual_distance = (
                    primary_distance < 50 or
                    primary_distance > 200
                )

        if unusual_distance:
            behaviors.append("unusual_distance")

        #  Severity 
        severity = self.calculate_severity(behaviors)

        #  Output 
        state = {
            "behaviors": behaviors,
            "severity": severity,
            "face_detected": face_detected,
            "face_count": face_count,
            "looking": is_looking,
            "primary_distance": primary_distance
        }

        msg = String()
        msg.data = json.dumps(state)
        self.publisher.publish(msg)

        # LOG OUTPUT
        self.get_logger().info(
            f"Behaviors: {behaviors} | Distance: {primary_distance:.2f} | Faces: {face_count} | Looking: {is_looking}"
        )

    #  Severity 

    def calculate_severity(self, behaviors):
        score = 0

        if "no_face" in behaviors:
            score += 2
        if "object_usage" in behaviors:
            score += 3
        if "multiple_faces" in behaviors:
            score += 2
        if "looking_away" in behaviors:
            score += 1
        if "unusual_distance" in behaviors:
            score += 1

        if score == 0:
            return "none"
        elif score <= 2:
            return "low"
        elif score <= 5:
            return "medium"
        else:
            return "high"


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
