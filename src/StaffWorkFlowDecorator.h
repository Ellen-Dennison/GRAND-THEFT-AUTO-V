#ifndef STAFFWORKFLOWDECORATOR_H
#define STAFFWORKFLOWDECORATOR_H
#include "StaffWorkFlow.h"


class StaffWorkFlowDecorator : public StaffWorkFlow{
    protected:
              StaffWorkFlow *wrappedStaff;
    public:
              StaffWorkFlowDecorator(StaffWorkFlow *staff);
              ~StaffWorkFlowDecorator();
              virtual void performMorningTasks();
              virtual void performAfternoonTasks();
              virtual std::string getName() const override;
              void displayRoles() override;
              std::string getType() override;

};
#endif
