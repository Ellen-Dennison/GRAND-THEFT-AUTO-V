#ifndef STAFFDECORATOR_H
#define STAFFDECORATOR_H
#include "StaffWorkflow.h"

class StaffDecorator : public StaffWorkflow{
    public:
            virtual void Staff();
            StaffDecorator(StaffWorkFlow* wrappedStaff);
            virtual ~StaffDecorator();
    private:
            Plant* wrappedStaff;
};
#endif