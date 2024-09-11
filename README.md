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
[x y theta]

# Differential kinematics
## Velocity

### linear velocity
total_linear_velo = (v_wheel_1 + v_wheel_2) / 2
v_wheel_1 = (w_right * phi_right_dot) / 2 + (w_left * phi_left_dot) / 2

### angular velocity
total_angular_velo = (w_left*phi_left_dot)/ws - (w_right*phi_right_dot)/ws

### total velo

         [  w_right/2   w_right/2   ]   [ phi_right_dot ]
[v w]T = |                          | * |               | 
         [  w_right/ws  w_right/ws  ]   [ phi_left_dot  ]

## velocity in the world frame

[   x_dot   ]   [ cos(theta) -sin(theta)  0 ]    [ v ]
|   y_dot   | = | sin(theta)  cos(theta)  0 |  * | 0 | 
[ theta_dot ]   [    0         0          1 ]    [ w ]

## Forward Kinematics 
[   x_dot   ]   [ w_right*cos(theta)/2  w_right*cos(theta)/2 ]    [ phi_right_dot ]
|   y_dot   | = | w_right*sin(theta)/2  w_right*sin(theta)/2 |  * |               | 
[ theta_dot ]   [      w_right/ws            -w_right/ws     ]    [ phi_left_dot  ]

# Angle Representations
    - Euler Angle
    - Quaternion

## Euler Angles
                        [cos(theta) -sin(theta) 0]
rotation about z axis:  |sin(theta) cos(theta)  0|   YAW
                        [     0          0      1]


                        [cos(phi)  0   -sin(phi)  ]
rotation about y axis:  |0         1      0       |  PITCH
                        [-sin(phi) 0    cos(phi)  ]


                        [1      0         0    ]
rotation about x axis:  |0  cos(psi) -sin(psi) |     ROLL
                        [0  sin(psi)  cos(psi) ]


## Quaternion

q = a + bi + cj + dk

Unitary: a^2 + b^2 + c^2 + d^2 = 1

Rotation COmposition: q_1 * q_2

Inverse: q^(-1) = a - bi - cj -dk

# Localization

- Wheel Odometry
- Laser Odometry
- Visual Odometry

## Wheel Odometry

Encoder sensor is use to get the number of the rotation
Light reciever provides a binary information 1 or 0, depending on whether it recieves the light beam from the light source or not.
More advanced encoders: absolute encoders

## Differential Inverse Kinematics

  [ v ]    [ wheel_radius/2                              wheel_radius/2    ]   [ phi_dot_right  ]
* |   | =  |                                                               | * |                |
  [ w ]    [ wheel_radius/wheel_separation   -wheel_radius/wheel_separation]   [ Phi_dot_left   ]

* v = s * t

* phi_dor_right = (phi_1_right - phi_0_right) / (t_1 - t_0) = delta_phi_right / delta_t 
* phi_dor_left = (phi_1_left - phi_0_left) / (t_1 - t_0)  = delta_phi_left / delta_t
* v = wheel_radius/2 * delta_phi_right / delta_t + wheel_radius/2 * delta_phi_left / delta_t
* w = wheel_radius/wheel_separation * delta_phi_right / delta_t + wheel_radius/wheel_separation * delta_phi_left / delta_t

wheel odometry:
---------------

pos = integral v dt => integral (wheel_radius*phi_dot_right / 2 + wheel_radius*phi_dot_left / 2) dt 
                       = wheel_radius * delta_phi_right / 2 + wheel_radius * delta_phi_left / 2

orientation = integral w dt = integral (wheel_radius * phi_dot_right / wheel_separation - wheel_radius * phi_dot_left / wheel_separation) dt
            = wheel_radius * delta_phi_right / wheel_separation - wheel_radius * delta_phi_left / wheel_separation
