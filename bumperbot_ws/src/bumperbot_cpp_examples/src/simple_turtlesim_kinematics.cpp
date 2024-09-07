#include "bumperbot_cpp_examples/simple_turtlesim_kinematics.hpp"

using std::placeholders::_1;

SimpleTurtlesimKinemetics::SimpleTurtlesimKinemetics(const std::string& name) : rclcpp::Node(name)
{
    turtle1_pose_sub_ = create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&SimpleTurtlesimKinemetics::turtle1PoseCallback, _1));
    turtle2_pose_sub_ = create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, std::bind(&SimpleTurtlesimKinemetics::turtle2PoseCallback, _1));
}
    
void SimpleTurtlesimKinemetics::turtle1PoseCallback(const turtlesim::msg::Pose& pose)
{
    last_turtle1_pose_ = pose;
}

void SimpleTurtlesimKinemetics::turtle2PoseCallback(const turtlesim::msg::Pose& pose)
{
    last_turtle2_pose_ = pose;
    float Tx = last_turtle2_pose_.x - last_turtle1_pose_.x;
    float Ty = last_turtle2_pose_.y - last_turtle1_pose_.y;

    RCLCPP_INFO_STREAM(get_logger(), "\nTranslation vector turtle1 -> turtle2 \n" << "Tx: " << Tx << "\nTy: " << Ty << "\n");
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleTurtlesimKinemetics>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}