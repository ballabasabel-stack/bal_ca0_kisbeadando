import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32

class TrigSubscriber(Node):
    def __init__(self):
        super().__init__('trig_subscriber')
        self.sub_sin = self.create_subscription(Float32,'sin_wave',self.sin_callback,10)

        self.sub_cos = self.create_subscription(Float32,'cos_wave',self.cos_callback,10)
        self.get_logger().info('TrigSubscriber node elindult')

    def sin_callback(self, msg):
        self.get_logger().info(f'Received sin: {msg.data:.2f}')

    def cos_callback(self, msg):
        self.get_logger().info(f'Received cos: {msg.data:.2f}')


def main():
    rclpy.init()
    node = TrigSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
