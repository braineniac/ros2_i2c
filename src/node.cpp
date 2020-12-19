#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"


using namespace std::chrono_literals;

class ServoSub: public rclcpp::Node
{
    public ServoSub(): Node("servoSub"), count(0)
    {
        
    }
}