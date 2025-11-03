#ifndef SalesFloorWorker_H
#define SalesFloorWorker_H

#include "StaffWorkFlow.h"
#include <map>

// Forward declarations
class NurseryMediator;
class Customer;

/**
 * @brief A derived class of the StaffWorkFlow class. A specialisation of StaffWorkFlow.
 * Type of staff member.
*/

class SalesFloorWorker : public StaffWorkFlow {
    protected:
    /**
     * @brief pointer to NurseryMediator object used to communicate to
    */
        NurseryMediator* mediator;  // Reference to mediator, NOT salesFloor
        
    public:
    /**
     * @brief Constructor for this class
     * @param name, a string, med, a pointer to a NurseryMediator object
    */
        SalesFloorWorker(std::string name, NurseryMediator* med);
        
    /**
     * @brief performs sales floor maintenance
     */
        void performMorningTasks() override;
    
    /**
     * @brief managing afternoon sales floor care
     */
        void performAfternoonTasks() override;
    
    /**
     * @brief gets the type of worker
     * @return "Sales Associate"
     */
        std::string getType() override;
    
    /**
     * @brief displays all the roles of the worker including the additional role of being a Sales Associate
    */
        void displayRoles() override;
};

#endif
