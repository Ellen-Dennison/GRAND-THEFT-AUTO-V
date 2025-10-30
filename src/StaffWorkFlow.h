#ifndef STAFFWORKFLOW_H
#define STAFFWORKFLOW_H
#include<string>

class StaffWorkFlow{//abstract class
    protected:
                std::string staffName;
                void clockIn();
                void clockOut();
                void takeBreak();
                
    public:
                virtual std::string getName();
                virtual std::string getType() = 0;
                virtual void displayRoles() = 0;
                void executeWorkDay();
                virtual void performMainTask() = 0;//!Can't be accessed by function
                virtual ~StaffWorkFlow();

};
#endif