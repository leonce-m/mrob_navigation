#pragma once
#include <smacc/smacc.h>
#include <smacc/smacc_client.h>

#include <mrob_navigation/SetTurtlebotMode.h>

namespace sm_mrob_turtlebot 
{
    class ClSetTurtlebotModeServiceServer : public smacc::ISmaccClient
    {
    public:
        boost::optional<std::string> serviceName;
        
        ClSetTurtlebotModeServiceServer()
        {
            initialized_ = false;
        }

        virtual ~ClSetTurtlebotModeServiceServer()
        {
            srv_.shutdown();
        }

        void configure(std::string serviceName) {
            this->serviceName = serviceName;
            if (!initialized_) {
                if (!this->serviceName) {
                    ROS_ERROR("service server with no service name set. Skipping advertising.");
                    return;
                }
                ROS_INFO_STREAM("[" << this->getName() << "] Service Server with service: " << serviceName);
                srv_ = nh_.advertiseService(*(this->serviceName), &ClSetTurtlebotModeServiceServer::serviceCallback, this);
            }
        }
    protected:
        ros::NodeHandle nh_;
        ros::ServiceServer srv_;

    private:
        bool initialized_;

        bool serviceCallback(const mrob_navigation::SetTurtlebotMode::Request &req, const mrob_navigation::SetTurtlebotMode::Response &res) {

            return true;
        }
    };
}