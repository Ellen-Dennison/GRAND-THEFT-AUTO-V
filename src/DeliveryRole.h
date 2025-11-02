#ifndef DELIVERYROLE_H
#define DELIVERYROLE_H
#include "StaffWorkFlowDecorator.h"


class DeliveryRole : public StaffWorkFlowDecorator{
    protected:
                void performMorningTasks();
                void performAfternoonTasks();
    public:
                DeliveryRole(StaffWorkFlow* staff);
                std::string getType() override;
                void displayRoles() override;
};
#endif
