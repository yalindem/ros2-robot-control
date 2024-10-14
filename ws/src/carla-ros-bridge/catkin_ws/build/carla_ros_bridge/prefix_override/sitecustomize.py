import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/media/yalin/m2/workspace/carla-ros-bridge/catkin_ws/install/carla_ros_bridge'
