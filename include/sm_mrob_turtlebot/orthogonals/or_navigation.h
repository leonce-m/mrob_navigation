#pragma once
#include <smacc/smacc_orthogonal.h>
#include <move_base_z_client_plugin/move_base_z_client_plugin.h>
#include <move_base_z_client_plugin/components/odom_tracker/odom_tracker.h>
#include <move_base_z_client_plugin/components/waypoints_navigator/waypoints_navigator.h>
#include <move_base_z_client_plugin/components/pose/cp_pose.h>

namespace sm_mrob_turtlebot
{
using namespace cl_move_base_z;

class OrNavigation : public smacc::Orthogonal<OrNavigation>
{
public:
    virtual void onInitialize() override
    {
        auto movebaseClient_ = this->createClient<ClMoveBaseZ>();
        movebaseClient_->initialize();

        movebaseClient_->createComponent<Pose>();

        // create odom tracker
        movebaseClient_->createComponent<cl_move_base_z::odom_tracker::OdomTracker>();

        // create waypoints navigator component
        auto waypointsNavigator = movebaseClient_->createComponent<WaypointNavigator>();
    }
};
} // namespace sm_mrob_turtlebot