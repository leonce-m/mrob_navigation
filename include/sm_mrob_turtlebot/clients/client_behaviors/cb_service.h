#include <smacc/smacc_client_behavior.h>
#include <sm_mrob_turtlebot/clients/cl_service.h>

namespace sm_mrob_turtlebot
{
    class CbService : public smacc::SmaccClientBehavior
    {
    private:
        ClService *serviceClient_;
        
    public:
        CbService() {}

        virtual void onEntry() override
        {
            this->requiresClient(serviceClient_);

        }
    };
}