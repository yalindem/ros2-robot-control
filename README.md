# ros2-robot-control

Install Extensions in vscode
- CMakeTools
- XML
- ros

Install ros2 packages

ros-humble-ros2-controllers
ros-humble-xacro
ros-humble-gazebo-ros
ros-humble-gazebo-ros-pkgs
ros-humble-ros2-control
ros-humble-gazebo-ros2-control
ros-humble-joint-state-publisher-gui
ros-humble-turtlesim
ros-humble-robot-localization
ros-humble-joy-teleop
ros-humble-tf-transformations
ros-humble-plotjuggler
ros-humble-plotjuggler-ros

sudo apt install python3-pip
pip install transform3d

DDS middleware
--------------
* communication protocol
* can be implemented self-DDS-version

# Mobile Robots
There are 3 different artitechtures for locomations
- Differential Drive
- Ackerman Drive
- Omnidirectional Drive

For Differential Drive the state space vector:
$$   
\begin{bmatrix} x & y & theta \end{bmatrix}
$$
