
#ifndef GRAND_THEFT_AUTO_V_STAFFWORKFLOW_H
#define GRAND_THEFT_AUTO_V_STAFFWORKFLOW_H

#include <string>

class NurseryMediator;

class StaffWorkflow {
protected:
    std::string staffName;
    NurseryMediator* mediator;

public:
    StaffWorkflow(const std::string& n, NurseryMediator* m);
    virtual ~StaffWorkflow();

     virtual void performMainTask() = 0;

};


#endif //GRAND_THEFT_AUTO_V_STAFFWORKFLOW_H
