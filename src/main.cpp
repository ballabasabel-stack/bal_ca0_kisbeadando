#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class tangens : public rclcpp::Node
{
public:
    tangens() : Node("main"), count_(0)
        {
            RCLCPP_INFO(this->get_logger(), "tangens jelgenerátor");
            pub1_ = this->create_publisher<std_msgs::msg::Float32>("tan1", 10);
            pub2_ = this->create_publisher<std_msgs::msg::Float32>("tan2", 10);
            timer_ = this->create_wall_timer(50ms, std::bind(&tangens::timer_callback, this));
        }
    

private:
    void timer_callback()
    {
        auto msg1 = std_msgs::msg::Float32();
        auto msg2 = std_msgs::msg::Float32();

        auto t = count_ * 0.01;
        msg1.data = cos(t * 2 * M_PI  *1) * 2 ;  
        msg1.data = cos(t * 2 * M_PI  *1) ; 
        pub1_->publish(msg1);
        pub2_->publish(msg2);

        count_++;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub1_, pub2_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<tangens>());
    rclcpp::shutdown();
    return 0;
}