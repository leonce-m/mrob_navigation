#pragma once
#include <smacc/smacc_orthogonal.h>
#include <sm_mrob_turtlebot/clients/cl_service.h>

namespace sm_mrob_turtlebot 
{
    class OrServices : public smacc::Orthogonal<OrServices>
    {
        virtual void onInitialize() override 
        {
            auto service_server_ = this->createClient<ClServiceServer>("set_mode");
            service_server_->initialize();
        }
    };
}