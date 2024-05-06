#include "psub2_2/pub2_2.hpp"

Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
}
void Pub::publish_msg()
{
    static float number_X = 0, number_Y = 0, number_Z = 0;
    geometry_msgs::msg::Vector3 msg;
    msg.x = number_X++;
    msg.y = number_Y++;
    msg.z = number_Z++;
    RCLCPP_INFO(this->get_logger(), "x: %lf y: %lf z: %lf\n", msg.x, msg.y, msg.z);
    pub_->publish(msg);
}