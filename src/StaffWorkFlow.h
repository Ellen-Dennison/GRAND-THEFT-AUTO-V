#ifndef STAFFWORKFLOW_H
#define STAFFWORKFLOW_H
#include <string>

#include "Customer.h"

class StaffWorkFlow{//abstract class
    protected:
                std::string staffName;
                void clockIn();
                void clockOut();
                void takeBreak();
                
    public:
                virtual std::string getName() const;
                virtual std::string getType() = 0;
                virtual void displayRoles() = 0;
                virtual void executeWorkDay();
                virtual void performMorningTasks() = 0;
                virtual void performAfternoonTasks() = 0;
                virtual ~StaffWorkFlow();
                virtual void assistCustomer(Customer* customer);

};
#endif
