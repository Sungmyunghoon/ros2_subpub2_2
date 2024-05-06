#include "psub2_2/sub2_2.hpp"
void Sub::subscribe_msg(const geometry_msgs::msg::Vector3::SharedPtr msg) const
{
    RCLCPP_INFO(this->get_logger(), "Received x: '%lf' Received y: '%lf' Received z: '%lf'", msg->x, msg->y, msg->z);
}
Sub::Sub() : Node("mysub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    sub_ = this->create_subscription<geometry_msgs::msg::Vector3>("mytopic", qos_profile, std::bind(&Sub::subscribe_msg, this, _1));
}