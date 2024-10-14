#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <nav_msgs/msg/odometry.hpp>

class CarlaLocalizationNode : public rclcpp::Node
{
    public:
        CarlaLocalizationNode() : Node("carla_localization_node")
        {
            // Create subscribers for GPS, IMU, and Odometry data
            gps_subscriber_ = this->create_subscription<sensor_msgs::msg::NavSatFix>(
                "/carla/ego_vehicle/gnss", 10,
                std::bind(&CarlaLocalizationNode::gps_callback, this, std::placeholders::_1));

            imu_subscriber_ = this->create_subscription<sensor_msgs::msg::Imu>(
                "/carla/ego_vehicle/imu", 10,
                std::bind(&CarlaLocalizationNode::imu_callback, this, std::placeholders::_1));

            odom_subscriber_ = this->create_subscription<nav_msgs::msg::Odometry>(
                "/carla/ego_vehicle/odometry", 10,
                std::bind(&CarlaLocalizationNode::odom_callback, this, std::placeholders::_1));
        }

    private:
        void gps_callback(const sensor_msgs::msg::NavSatFix::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "GPS Location: Latitude: %.6f, Longitude: %.6f, Altitude: %.2f",
                        msg->latitude, msg->longitude, msg->altitude);
        }

        void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "IMU Orientation: [%f, %f, %f, %f]",
                        msg->orientation.x, msg->orientation.y,
                        msg->orientation.z, msg->orientation.w);
        }

        void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "Odometry Position: [%.2f, %.2f, %.2f]",
                        msg->pose.pose.position.x,
                        msg->pose.pose.position.y,
                        msg->pose.pose.position.z);
        }

        rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr gps_subscriber_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscriber_;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CarlaLocalizationNode>());
    rclcpp::shutdown();
    return 0;
}
