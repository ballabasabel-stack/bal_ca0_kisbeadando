import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import math

class TrigPublisher(Node):
    def __init__(self):
        super().__init__('trig_publisher')
        self.sin_pub = self.create_publisher(Float32, 'sin_wave', 10)
        self.cos_pub = self.create_publisher(Float32, 'cos_wave', 10)

        # Paraméterek (könnyen állítható)
        self.declare_parameter('amplitude', 10.0)   # <- ide állítsd: 10.0
        self.declare_parameter('frequency', 1.0)    # Hz
        self.declare_parameter('rate', 50.0)        # publish rate (Hz)

        self.amplitude = float(self.get_parameter('amplitude').value)
        self.frequency = float(self.get_parameter('frequency').value)
        self.rate = float(self.get_parameter('rate').value)

        self.dt = 1.0 / self.rate
        self.t = 0.0

        # timer a mintavételhez
        self.timer = self.create_timer(self.dt, self.timer_callback)

        self.get_logger().info(
            f'Started trig_publisher: A={self.amplitude}, f={self.frequency}Hz, rate={self.rate}Hz'
        )

    def timer_callback(self):
        omega = 2.0 * math.pi * self.frequency
        sin_v = self.amplitude * math.sin(omega * self.t)
        cos_v = self.amplitude * math.cos(omega * self.t)

        self.sin_pub.publish(Float32(data=sin_v))
        self.cos_pub.publish(Float32(data=cos_v))

        # Use debug/INFO to see actual numbers
        self.get_logger().debug(f'Published sin={sin_v:.3f} cos={cos_v:.3f}')

        self.t += self.dt


def main(args=None):
    rclpy.init(args=args)
    node = TrigPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
