import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter

class SimpleParameter(Node):
    def __init__(self):
        super().__init__("simple_parameter")
        
        self.declare_paremeter("simple_int_param", 20)
        self.declare_parameter("simple_string_param", "yalin")
        
        self.add_on_set_parameters_callback(self.paramChangeCallback)

    def paramChangeCallback(self, params) -> SetParametersResult:
        result = SetParametersResult()
        for param in params:
            if param.name == "simple_int_param" and param.type == Parameter.Type.INTEGER:
                self.get_logger().info("param simple_int_param changed! New value is %d" % param.value)
                result.successful = True

            if param.name == "simple_string_param" and param.type == Parameter.Type.STRING:
                self.get_logger().info("param simple_string_param changed! New value is %s" % param.value)
                result.successful = True
        return result
    
def main():
    rclpy.init()
    simpleParameter = SimpleParameter()
    rclpy.spin(simpleParameter)
    simpleParameter.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()