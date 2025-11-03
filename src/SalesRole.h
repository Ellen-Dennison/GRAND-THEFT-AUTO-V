#ifndef SALESROLE_H
#define SALESROLE_H
#include "StaffWorkFlowDecorator.h"

class SalesRole : public StaffWorkFlowDecorator
{
    protected:
                void performMorningTasks();
                void performAfternoonTasks();
    public:
                SalesRole(StaffWorkFlow* staff);
                std::string getType() override;
                void displayRoles() override;
};
#endif
