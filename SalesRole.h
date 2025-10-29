#ifndef SALESROLE_H
#define SALESROLE_H
#include "StaffWorkFlowDecorator.h"

class SalesRole : public StaffWorkFlowDecorator{
    protected:
                void performMainTask();
    public:
                SalesRole(StaffWorkFlow* staff);
};
#endif