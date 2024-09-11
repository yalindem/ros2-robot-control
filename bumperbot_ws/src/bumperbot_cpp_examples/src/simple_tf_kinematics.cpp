#include "bumperbot_cpp_examples/simple_tf_kinematics.hpp"

using namespace std::chrono_literals;
using namespace std::placeholders;

SimpleTfkinematics::SimpleTfkinematics(const std::string& name) : Node(name), x_increment_(0.05), last_x_(0.0), rotations_counter_{0}
{

    dynamic_tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
    static_tf_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    static_transform_stamped_.header.stamp = get_clock()->now();
    static_transform_stamped_.header.frame_id = "bumperbot_base";
    static_transform_stamped_.child_frame_id = "bumperbot_top";
    static_transform_stamped_.transform.translation.x = 0.0;
    static_transform_stamped_.transform.translation.y = 0.0;
    static_transform_stamped_.transform.translation.z = 0.3;

    static_transform_stamped_.transform.rotation.x = 0.0; 
    static_transform_stamped_.transform.rotation.y = 0.0;
    static_transform_stamped_.transform.rotation.z = 0.0;
    static_transform_stamped_.transform.rotation.w = 1.0;

    static_tf_broadcaster_->sendTransform(static_transform_stamped_);
    RCLCPP_INFO_STREAM(get_logger(), "Publishing static transform between " << static_transform_stamped_.header.frame_id << " and " << static_transform_stamped_.child_frame_id);

    timer_ = create_wall_timer(0.1s, std::bind(&SimpleTfkinematics::timerCallback, this));

    get_transform_srv_ = create_service<bumperbot_msgs::srv::GetTransform>("get_transform", std::bind(&SimpleTfkinematics::getTransformCallback, this, _1, _2));

    last_orientation_.setRPY(0, 0, 0);
    orientation_increment_.setRPY(0, 0, 0.05);
}

void SimpleTfkinematics::timerCallback()
{
    dynamic_transform_stamped_.header.stamp = get_clock()->now();
    dynamic_transform_stamped_.header.frame_id = "odom";
    dynamic_transform_stamped_.child_frame_id = "bumperbot_base";
    dynamic_transform_stamped_.transform.translation.x = last_x_ + x_increment_;
    dynamic_transform_stamped_.transform.translation.y = 0.0;
    dynamic_transform_stamped_.transform.translation.z = 0.0;

    tf2::Quaternion q;
    q = last_orientation_ * orientation_increment_;
    q.normalize();

    dynamic_transform_stamped_.transform.rotation.x = q.getX();
    dynamic_transform_stamped_.transform.rotation.y = q.getY();
    dynamic_transform_stamped_.transform.rotation.z = q.getZ();
    dynamic_transform_stamped_.transform.rotation.w = q.getW();

    dynamic_tf_broadcaster_->sendTransform(dynamic_transform_stamped_);
    last_x_ = dynamic_transform_stamped_.transform.translation.x; 

    rotations_counter_++;
    last_orientation_ = q;
    if(rotations_counter_ >= 100)
    {
        orientation_increment_ = orientation_increment_.inverse();
        rotations_counter_ = 0;
    }
}

bool SimpleTfkinematics::getTransformCallback(const std::shared_ptr<bumperbot_msgs::srv::GetTransform::Request>& req, 
                                  const std::shared_ptr<bumperbot_msgs::srv::GetTransform::Response>& res)
{
    geometry_msgs::msg::TransformStamped requested_transform;
    
    try{
        requested_transform = tf_buffer_->lookupTransform(req->frame_id, req->child_frame_id, tf2::TimePointZero);
    }
    catch(tf2::TransformException &ex)
    {
        RCLCPP_ERROR(get_logger(), "an error occured while transforming; ");
        res->success = false;
        return true;
    }   
    res->success = true;
    return true;

}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleTfkinematics>("simple_tf_kinematics");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}