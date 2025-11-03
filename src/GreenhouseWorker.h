#ifndef GREENHOUSEWORKER_H
#define GREENHOUSEWORKER_H
#include "StaffWorkFlow.h"

// Forward declaration
class NurseryMediator;

/**
 * @brief A derived class of the StaffWorkFlow class. A specialisation of StaffWorkFlow.
 * Type of staff member.
 */

class GreenhouseWorker : public StaffWorkFlow {
    protected:
    /**
     * @brief pointer to NurseryMediator object used to communicate to
     */
        NurseryMediator* mediator;  // Reference to mediator, NOT plants
        
    public:
    /**
     * @brief Constructor for this class
     * @param name, a string, med, a pointer to a NurseryMediator object
     */
        GreenhouseWorker(std::string name, NurseryMediator* med);
        
    /**
     * @brief performs morning tasks of the greenhouse worker
    */
        void performMorningTasks() override;
    
    /**
     * @brief performs morning tasks of the greenhouse worker
    */
        void performAfternoonTasks() override;
    
    /**
     * @brief gets the type of the worker, "greenhouse worker"
     * @return "Greenhouse Worker"
    */
        std::string getType() override;
    
    /**
     * @brief displays greenhouse worker as the role and additional roles
    */
        void displayRoles() override;
};

#endif
