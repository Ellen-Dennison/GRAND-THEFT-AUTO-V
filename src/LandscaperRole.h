#ifndef LANDSCAPERROLE_H
#define LANDSCAPERROLE_H
#include "StaffWorkFlowDecorator.h"

/**
 * @brief One of the concrete decorators of the StaffWorkFlowDecorator class.
 * adds the responsibilities of a landscaper. These are behavioral-based responsibilities.
 */
class LandscaperRole : public StaffWorkFlowDecorator{
    protected:
        /**
         * @brief morning tasks of a landscaper to keep landscapes healthy
         */
                void performMorningTasks();
        
        /**
         * @brief afternoon tasks of a landscaper to keep landscapes healthy
         */
                void performAfternoonTasks();
    public:
        /**
         * @brief Constructor of this class which returns a new landscaperRole object
         * @return LandscaperRole object
         * @param staff Pointer to a StaffWorkFlow object
         */
            LandscaperRole(StaffWorkFlow* staff);
        
        /**
         * @brief gets the type of the work
         */
            std::string getType() override;
        
        /**
         * @brief displays all the roles of the work including the role of being a landscaper
        */
            void displayRoles() override;
};
#endif
