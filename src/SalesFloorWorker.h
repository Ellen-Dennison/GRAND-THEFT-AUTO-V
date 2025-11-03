#ifndef SalesFloorWorker_H
#define SalesFloorWorker_H

#include "StaffWorkFlow.h"
#include <map>

// Forward declarations
class NurseryMediator;
class Customer;

class SalesFloorWorker : public StaffWorkFlow {
    protected:
        NurseryMediator* mediator;  // Reference to mediator, NOT salesFloor
        
    public:
        SalesFloorWorker(std::string name, NurseryMediator* med);
        
        void performMorningTasks() override;
        void performAfternoonTasks() override;
        
        std::string getType() override;
        void displayRoles() override;
};

#endif
