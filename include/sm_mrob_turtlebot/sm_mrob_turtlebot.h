#include <smacc/smacc.h>

#include <ros_timer_client/client_behaviors/cb_ros_timer.h>
#include <ros_publisher_client/client_behaviors/cb_publish_once.h>

#include <move_base_z_client_plugin/move_base_z_client_plugin.h>
#include <move_base_z_client_plugin/client_behaviors.h>

#include <sm_mrob_turtlebot/orthogonals/or_navigation.h>
#include <sm_mrob_turtlebot/orthogonals/or_exploration.h>
#include <sm_mrob_turtlebot/orthogonals/or_timer.h>
#include <sm_mrob_turtlebot/orthogonals/or_update_publisher.h>
#include <sm_mrob_turtlebot/orthogonals/or_services.h>

// FORWARD DECLARATIONS
namespace sm_mrob_turtlebot
{
    //STATE FORWARD DECLARATIONS
    class StIdle;
    class StTeleop;
    class StWaitForFrontier;
    class StWaitForUserGoal;
    class StNavigateToWaypoint;

    //SUPERSTATE FORWARD DECLARATIONS
    class SsAutoExploration;
    class SsUserNavigation;
} // namespace sm_mrob_turtlebot

using namespace sm_mrob_turtlebot;
using namespace cl_move_base_z;
using namespace cl_ros_timer;
using namespace cl_ros_publisher;
using namespace smacc;

namespace sm_mrob_turtlebot
{
struct SmMrobTurtlebot : public smacc::SmaccStateMachineBase<SmMrobTurtlebot, StIdle> 
{

    typedef mpl::bool_<false> shallow_history;
    typedef mpl::bool_<false> deep_history;
    typedef mpl::bool_<false> inherited_deep_history;

    using SmaccStateMachineBase::SmaccStateMachineBase;

    virtual void onInitialize() override {
        this->createOrthogonal<OrNavigation>();
        //this->createOrthogonal<OrExploration>();
        this->createOrthogonal<OrTimer>();
        this->createOrthogonal<OrUpdatePublisher>();
        this->createOrthogonal<OrServices>();
    }
};
} // namespace sm_mrob_turtlebot

//SUPERSTATES
#include <sm_mrob_turtlebot/superstates/ss_auto_exploration.h>
#include <sm_mrob_turtlebot/superstates/ss_user_navigation.h>

//STATES
#include <sm_mrob_turtlebot/states/st_idle.h>
#include <sm_mrob_turtlebot/states/st_teleop.h>
#include <sm_mrob_turtlebot/states/st_wait_for_frontier.h>
#include <sm_mrob_turtlebot/states/st_wait_for_user_goal.h>
#include <sm_mrob_turtlebot/states/st_navigate_to_waypoint.h>