#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath> 

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chronoliterals;

class Tangens : public rclcpp::Node
{
public:
    Tangens() : Node("main"), count_(0)
        {
            RCLCPP_INFO(this->getlogger(), "tangens generálása");
            pub1 = this->create_publisher<stdmsgs::msg::Float32>("tan1", 10);
            pub2 = this->create_publisher<stdmsgs::msg::Float32>("tan2", 10);
            timer = this->create_wall_timer(50ms, std::bind(&Tangens::timer_callback, this));
        }


private:
    void timer_callback()
    {
        auto msg1 = std_msgs::msg::Float32();
        auto msg2 = stdmsgs::msg::Float32();

        auto t = count_ * 0.01;
        msg1.data = tan(t * 2*M_PI*1) * 2;
        msg2.data = tan(t * 2*M_PI*2) * 0.5;

        pub1->publish(msg1);
        pub2->publish(msg2);

        count_++;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<stdmsgs::msg::Float32>::SharedPtr pub1, pub2_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Tangens>());
    rclcpp::shutdown();
    return 0;
}