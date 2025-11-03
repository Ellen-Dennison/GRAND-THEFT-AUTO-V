#ifndef STAFFWORKFLOW_H
#define STAFFWORKFLOW_H
#include <string>

#include "Customer.h"


/**
 * @brief Abstract class representing a general staff entitiy
 * 
 * The StaffWorkFlow class encapsulates attributes and behaviors common to all staff members.
 * It defines interfaces for operations that each staff member will do (clocking in, clocking out, taking a break,
 * performing morning tasks and afternoon tasks)
 * getting the type of a staff member since each staff member has their own specific role. It forms part of the Template Method
 * and the Decorator design pattern. It is the Component for the Decorator and the Abstract class that contains the template method
 * for the Template Method design pattern.
 */
class StaffWorkFlow{
    protected:
        /**
         * @brief The staff member's name
         */
                std::string staffName;
        
        /**
         * @brief The function that is called when the staff member clocks in
         */
                void clockIn();
        
        /**
         * @brief The function that is called when the staff member clocks out
         */
                void clockOut();
        
        /**
         * @brief The function that is called when the staff member takes a break during workday 
         */
                void takeBreak();
                
    public:
        /**
         * @brief The name of the staff member
         * @return the name of the staff member, a string variable
         */
                virtual std::string getName() const;
        
        /**
         * @brief Returns the type of staff member, e.g. Greenhouse worker, Sales Associate
         * implemented by derived classes
         */
                virtual std::string getType() = 0;

        /**
         * @brief Displays all the roles of the staff member (core role and extra roles if there's any)
         * implemented by derived classes
         */
                virtual void displayRoles() = 0;

        /**
         * @brief Shows the activities the staff member performed during work day, such as clocking in and clocking out
         */
                virtual void executeWorkDay();

        /**
         * @brief Shows all tasks the staff member performed in the morning
         * implemented by derived classes
         */
                virtual void performMorningTasks() = 0;

        /**
         * @brief Shows all the tasks the staff member performed in the afternoon
         * implemented by derived classes
         */
                virtual void performAfternoonTasks() = 0;
        
        /**
         * @brief Destructor for the StaffWorkFlow class
         */
                virtual ~StaffWorkFlow();

        /**
         * @brief Assists customer if this is a Sales Associate
         * @param customer Pointer to a Customer object
         */
                virtual void assistCustomer(Customer* customer);

};
#endif
