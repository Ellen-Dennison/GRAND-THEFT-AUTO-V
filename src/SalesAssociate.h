#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "StaffWorkFlow.h"

// Forward declarations
class NurseryMediator;
class Customer;

class SalesAssociate : public StaffWorkFlow {
    private:
        NurseryMediator* mediator;  // Reference to mediator, NOT salesFloor
        
    public:
        SalesAssociate(std::string name, NurseryMediator* med);
        
    protected:
        void performMainTask() override;
        
    public:
        std::string getType() override;
        void displayRoles() override;
        void assistCustomer(Customer* customer);
};

#endif