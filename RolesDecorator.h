#ifndef ROLESDECORATOR_H
#define ROLESDECORATOR_H
#include "StaffDecorator.h"
#include "StaffWorkFlow.h"

class RolesDecorator: public StaffDecorator{
    public:
            StaffDecorator(StaffWorkFlow* wrappedStaff);
            void printStaff();
};
#endif