import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/menna/Distributed-Smart-Exam-Proctoring-System-using-ROS2/install/exam_proctoring_pkg'
