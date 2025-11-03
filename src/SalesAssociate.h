#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H

#include "StaffWorkFlow.h"
#include <map>

// Forward declarations
class NurseryMediator;
class Customer;

/**
 * @brief A derived class of the StaffWorkFlow class. A specialisation of StaffWorkFlow.
 * Type of staff member.
*/

class SalesAssociate : public StaffWorkFlow {
    protected:
    /**
     * @brief pointer to NurseryMediator object used to communicate to
    */
        NurseryMediator* mediator;  // Reference to mediator
        
    public:
    /**
     * @brief Constructor for this class
     * @param name, a string, med, a pointer to a NurseryMediator object
    */
        SalesAssociate(std::string name, NurseryMediator* med);
        
    /**
     * @brief performs morning tasks of the greenhouse worker
    */
        void performMorningTasks() override;
    
    /**
     * @brief performs morning tasks of the greenhouse worker
    */
        void performAfternoonTasks() override;
    
    /**
     * @brief executes all the activities the SalesAsociate has performed during the day
     */
        void executeWorkDay() override;
    
    /**
     * @brief gets the type of worker
     * @return "Sales Associate"
     */
        std::string getType() override;
    
    /**
     * @brief displays all the roles of the worker including the additional role of being a Sales Associate
     */
        void displayRoles() override;
    
    /**
     * @brief assists customer
     * @param customer Pointer to a Customer object
     */
        void assistCustomer(Customer* customer) override;
        
    /**
     * @brief explicit clock out so that they dont clock out before assisting
     */
        void endShift();
};

#endif
