#ifndef GREENHOUSEWORKER_H
#define GREENHOUSEWORKER_H
#include "StaffWorkFlow.h"

// Forward declaration
class NurseryMediator;

class GreenhouseWorker : public StaffWorkFlow {
    protected:

        NurseryMediator* mediator;  // Reference to mediator, NOT plants
        
    public:
        GreenhouseWorker(std::string name, NurseryMediator* med);
        
        void performMorningTasks() override;
        void performAfternoonTasks() override;
        
        std::string getType() override;
        void displayRoles() override;
};

#endif
