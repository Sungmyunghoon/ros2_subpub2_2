#include "psub2_2/pub2_2.hpp" // 헤더파일 포함

Pub::Pub() : Node("mypub"), count_(0) // 클래스의 생성자를 정의
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)); // Publish에 적용할 QoS 프로파일을 설정
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile); // vector형 메시지를 발행하는 발행자를 생성
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this)); // 타이머를 생성
}
void Pub::publish_msg() // 멤버 함수 정의
{
    static float number_X = 0, number_Y = 0, number_Z = 0; // 변수 선언
    geometry_msgs::msg::Vector3 msg;// vector형 정수 메시지 선언
    msg.x = number_X++; // 값이 증가되는 것을 메시지에 포함
    msg.y = number_Y++; // 값이 증가되는 것을 메시지에 포함
    msg.z = number_Z++; // 값이 증가되는 것을 메시지에 포함
    RCLCPP_INFO(this->get_logger(), "x: %lf y: %lf z: %lf\n", msg.x, msg.y, msg.z); // 메시지 전송
    pub_->publish(msg); // 메시지 발행
}
