#pragma once
#include <smacc/smacc_orthogonal.h>
#include <ros_timer_client/cl_ros_timer.h>

namespace sm_mrob_turtlebot
{
class OrTimer : public smacc::Orthogonal<OrTimer>
{
public:
    virtual void onInitialize() override
    {
        auto client = this->createClient<cl_ros_timer::ClRosTimer>(ros::Duration(1));
        client->initialize();
    }
};
} // namespace sm_mrob_turtlebot