# run the node
ros2 run bumperbot_cpp_examples simple_parameter

# check the parameters in the server
ros2 param list

# get the value of the param
ros2 param get /simple_parameter simple_int_param

# set the parameter
ros2 run bumperbot_cpp_examples simple_parameter --ros-args -p simple_int_param:=10