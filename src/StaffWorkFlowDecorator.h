#ifndef STAFFWORKFLOWDECORATOR_H
#define STAFFWORKFLOWDECORATOR_H
#include "StaffWorkFlow.h"

/**
 * @brief The Decorator class for the Staff management system.
 * It defines a reference to a StaffWorkFlow-type object.
 */
class StaffWorkFlowDecorator : public StaffWorkFlow{
    protected:
        /**
         * @brief The staff member to be decorated or attached additional responsibilities to
         */
              StaffWorkFlow *wrappedStaff;
    public:
        /**
         * @brief The constructor for this class
         * @param staff Pointer to a StaffWorkFlow object
         */
              StaffWorkFlowDecorator(StaffWorkFlow *staff);

        /**
         * @brief The destructor of this class, deletes any created StaffWorkFlowDecorator pointer created
         */
              ~StaffWorkFlowDecorator();
        
        /**
         * @brief attaches additional morning tasks if there is any
         */
              virtual void performMorningTasks();

        /**
         * @brief attaches additional afternoon tasks if there's any
         */
              virtual void performAfternoonTasks();

        /**
         * @brief gets the name of the staff member
         * @return name, a string variable
         */
              virtual std::string getName() const override;
        
        /**
         * @brief displays all the roles of the staff member
         */
              void displayRoles() override;
        
        /**
         * @brief gets the type of staff member
         */
              std::string getType() override;

};
#endif
