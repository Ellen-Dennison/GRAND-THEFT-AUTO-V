#ifndef MANAGERROLE_H
#define MANAGERROLE_H
#include "StaffWorkFlowDecorator.h"

/**
 * @brief One of the concrete decorators of the StaffWorkFlowDecorator class.
 * adds the responsibilities of a manager. These are behavioral-based responsibilities.
 */
class ManagerRole : public StaffWorkFlowDecorator{
    protected:
        /**
         * @brief morning tasks of a manager, managing other workers
         */
                void performMorningTasks();
        
        /**
         * @brief afternoon tasks of a manager, managing other workers
        */
                void performAfternoonTasks();
    public:
        /**
         * @brief Constructor of this class which returns a new ManagerRole object
         * @return ManagerRole object
         * @param staff Pointer to a StaffWorkFlow object
         */
                ManagerRole(StaffWorkFlow* staff);
        
         /**
         * @brief gets the type of the worker
         */
                std::string getType() override;
        
        /**
         * @brief displays all the roles of the work including the role of being a landscaper
        */
                void displayRoles() override;
};
#endif
