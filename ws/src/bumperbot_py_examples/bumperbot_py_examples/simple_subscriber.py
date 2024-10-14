import rclpy
from rclpy.node import Node

from std_msgs.msg import String

class SimpleSubscriber(Node):
    def __init__(self):
        super().__init__("simple_susbcriber")
        self.sub_ = self.create_subscription(String, "chatter", self.msgCallback, 10)

    def msgCallback(self, msg):
        self.get_logger().info("I heard: %s" % msg.data)

def main():
    rclpy.init()
    simpleSubscriber = SimpleSubscriber()
    rclpy.spin(simpleSubscriber)
    simpleSubscriber.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
