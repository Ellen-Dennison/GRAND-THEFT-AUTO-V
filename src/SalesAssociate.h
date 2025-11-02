#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "StaffWorkFlow.h"
#include <map>

// Forward declarations
class NurseryMediator;
class Customer;

class SalesAssociate : public StaffWorkFlow {
    protected:
        NurseryMediator* mediator;  // Reference to mediator
        
    public:
        SalesAssociate(std::string name, NurseryMediator* med);
        
        void performMorningTasks() override;
        void performAfternoonTasks() override;
        void executeWorkDay() override;
        
        std::string getType() override;
        void displayRoles() override;
        void assistCustomer(Customer* customer) override;
        
        void endShift();  //Explicit clock out so that they dont clock out before assisting
};

#endif
