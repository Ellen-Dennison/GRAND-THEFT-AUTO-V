#ifndef GREENHOUSEWORKER_H
#define GREENHOUSEWORKER_H
#include "StaffWorkFlow.h"

// Forward declaration
class NurseryMediator;

class GreenhouseWorker : public StaffWorkFlow {
    private:
        NurseryMediator* mediator;  // Reference to mediator, NOT plants 
        
    protected:
        void performMainTask() override;
        
    public:
        GreenhouseWorker(std::string name, NurseryMediator* med);
        std::string getType() override;
        void displayRoles() override;
        std::string getName() override;
};

#endif