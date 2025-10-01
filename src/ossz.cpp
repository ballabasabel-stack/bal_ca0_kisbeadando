#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class ossz : public rclcpp::Node
{
public:
    ossz() : Node("ossz"), val1received(false), val2received(false)
    {
        RCLCPP_INFO(this->getlogger(), "tangens generálása");
        pub = this->create_publisher<stdmsgs::msg::Float32>("ossz", 10);
        sub1 = this->create_subscription<std_msgs::msg::Float32>( "tan1", 10,std::bind(&ossz::callback1, this, std::placeholders::1));
        sub2 = this->create_subscription<std_msgs::msg::Float32>("tan2", 10,std::bind(&ossz::callback2, this, std::placeholders::_1));
    }

private:
    void callback1(const stdmsgs::msg::Float32::SharedPtr msg3)
        {
            val1 = msg3->data;
            val1received = true;
            publish_sum();
        }

    void callback2(const stdmsgs::msg::Float32::SharedPtr msg3)
        {
            val2 = msg3->data;
            val2received = true;
            publish_sum();
        }

    void publish_sum()
        {
        if (!val1received || !val2received) return; 

            auto sum_msg = std_msgs::msg::Float32();
            summsg.data = val1 + val2;
            pub->publish(sum_msg);
        }

    rclcpp::Publisher<stdmsgs::msg::Float32>::SharedPtr pub;
    rclcpp::Subscription<stdmsgs::msg::Float32>::SharedPtr sub1, sub2;
    float val1 = 0.0, val2_ = 0.0;
    bool val1received = false, val2received = false;

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ossz>());
    rclcpp::shutdown();
    return 0;
}