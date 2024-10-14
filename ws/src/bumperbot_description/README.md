# Requirements
sudo apt install ros-humble-urdf-tutorial 

# Visualize  the robot model
ros2 launch urdf_tutorial display.launch.py model:=/home/yalin/workspace/ros2-robot-control/bumperbot_ws/src/bumperbot_description/urdf/bumperbot.urdf.xacro 

# launch the robot in gazebo
ros2 launch bumperbot_description gazebo.launch.py