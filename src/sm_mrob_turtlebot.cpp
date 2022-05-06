#include <sm_mrob_turtlebot/sm_mrob_turtlebot.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mrob_turtlebot_smacc");
    ros::NodeHandle nh;

    ros::Duration(5).sleep();
    //smacc::run<SmMrobTurtlebot>();
}