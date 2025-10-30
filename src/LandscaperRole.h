#ifndef LANDSCAPERROLE_H
#define LANDSCAPERROLE_H
#include "StaffWorkFlowDecorator.h"

class LandscaperRole : public StaffWorkFlowDecorator{
    protected:
                void performMainTask();
    public:
            LandscaperRole(StaffWorkFlow* staff);
            std::string getType() override;
            void displayRoles() override;
};
#endif