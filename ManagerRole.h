#ifndef MANAGERROLE_H
#define MANAGERROLE_H
#include "StaffWorkFlowDecorator.h"

class ManagerRole : public StaffWorkFlowDecorator{
    protected:
                void performMainTask();
    public:
                ManagerRole(StaffWorkFlow* staff);
                std::string getType() override;
                void displayRoles() override;
};
#endif