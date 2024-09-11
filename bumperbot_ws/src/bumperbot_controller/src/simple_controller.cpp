#include "bumperbot_controller/simple_controller.hpp"
#include <Eigen/Geometry>

using std::placeholders::_1;

SimpleController::SimpleController(const std::string& name) : Node(name), left_wheel_prev_pos_{0}, right_wheel_prev_pos_{0}
{
    declare_parameter("wheel_radius", 0.033);
    declare_parameter("wheel_seperation", 0.17);

    wheel_radius_ = get_parameter("wheel_radius").as_double();
    wheel_seperation_ = get_parameter("wheel_seperation").as_double();

    RCLCPP_INFO_STREAM(get_logger(), "Using wheel_radius " << wheel_radius_);
    RCLCPP_INFO_STREAM(get_logger(), "Using wheel_seperation " << wheel_seperation_);

    prev_time_ = get_clock()->now();

    wheel_cmd_pub_ = create_publisher<std_msgs::msg::Float64MultiArray>("/simple_velocity_controller/commands", 10);
    vel_sub_ = create_subscription<geometry_msgs::msg::TwistStamped>("/bumperbot_controller/cmd_vel", 10, 
                    std::bind(&SimpleController::velCallback, this, _1));
    
    joint_sub_ = create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, std::bind(&SimpleController::jointCallback, this, _1));

    speed_conversion_(0, 0) = wheel_radius_ / 2;
    speed_conversion_(0, 1) = wheel_radius_ / 2;
    speed_conversion_(1, 0) = wheel_radius_ / wheel_seperation_;
    speed_conversion_(1, 1) = -wheel_radius_ / wheel_seperation_;
    RCLCPP_INFO_STREAM(get_logger(), "The conversion matrix is: \n" << speed_conversion_);
}

void SimpleController::velCallback(const geometry_msgs::msg::TwistStamped& msg)
{
    Eigen::Vector2d robot_speed(msg.twist.linear.x, msg.twist.angular.z);
    Eigen::Vector2d wheel_speed = speed_conversion_.inverse() * robot_speed;

    std_msgs::msg::Float64MultiArray wheel_speed_msg;
    wheel_speed_msg.data.push_back(wheel_speed.coeff(1));
    wheel_speed_msg.data.push_back(wheel_speed.coeff(0));

    wheel_cmd_pub_->publish(wheel_speed_msg);
}

void SimpleController::jointCallback(const sensor_msgs::msg::JointState& msg)
{
    double dp_left = msg.position.at(1) - left_wheel_prev_pos_;
    double dp_right = msg.position.at(0) - right_wheel_prev_pos_;
    rclcpp::Time msg_time = msg.header.stamp;
    rclcpp::Duration dt = msg_time - prev_time_;

    left_wheel_prev_pos_ = msg.position.at(1);
    right_wheel_prev_pos_ = msg.position.at(0);

    prev_time_ = msg_time;

    double fi_left = dp_left/dt.seconds();
    double fi_right = dp_right/dt.seconds();

    double linear = (wheel_radius_ * fi_right + wheel_radius_ * fi_left) / 2; 
    double angular = (wheel_radius_ * fi_right - wheel_radius_ * fi_left) / wheel_seperation_; 

    RCLCPP_INFO_STREAM(get_logger(), "linear: " << linear << " Angular: " << angular);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleController>("simple_controller");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}