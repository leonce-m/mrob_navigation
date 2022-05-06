#pragma once
#include <smacc/smacc_orthogonal.h>
#include <ros_publisher_client/cl_ros_publisher.h>
#include <std_msgs/String.h>

namespace sm_mrob_turtlebot
{
class OrUpdatePublisher : public smacc::Orthogonal<OrUpdatePublisher>
{
public:
    virtual void onInitialize() override
    {
        auto publisherClient_ = this->createClient<cl_ros_publisher::ClRosPublisher>();
        publisherClient_->configure<std_msgs::String>("/update_string_publisher_out");
    }
};
} // namespace sm_mrob_turtlebot