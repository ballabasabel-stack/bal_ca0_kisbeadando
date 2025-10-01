#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class ossz : public rclcpp::Node
{
public:
    ossz() : Node("ossz"), val1_received_(false), val2_received_(false)
    {
        RCLCPP_INFO(this->get_logger(), "tangens generálása");
        pub = this->create_publisher<stdmsgs::msg::Float32>("ossz", 10);
        sub1_ = this->create_subscription<std_msgs::msg::Float32>( "tan1", 10,std::bind(&ossz::callback1, this, std::placeholders::_1));
        sub2_ = this->create_subscription<std_msgs::msg::Float32>("tan2", 10,std::bind(&ossz::callback2, this, std::placeholders::_1));
    }

private:
    void callback1(const stdmsgs::msg::Float32::SharedPtr msg3)
        {
            val1_ = msg3->data;
            val1_received_ = true;
            publish_sum();
        }

    void callback2(const stdmsgs::msg::Float32::SharedPtr msg3)
        {
            val2_ = msg3->data;
            val2_received_ = true;
            publish_sum();
        }

    void publish_sum()
        {
        if (!val1_received_ || !val2_received_) return; 

            auto sum_msg = std_msgs::msg::Float32();
            summsg.data = val1_ + val2_;
            pub->publish(sum_msg);
        }

    rclcpp::Publisher<stdmsgs::msg::Float32>::SharedPtr pub_;
    rclcpp::Subscription<stdmsgs::msg::Float32>::SharedPtr sub1_, sub2_;
    float val1_ = 0.0, val2_ = 0.0;
    bool val1_received_ = false, val2_received_ = false;

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ossz>());
    rclcpp::shutdown();
    return 0;
}