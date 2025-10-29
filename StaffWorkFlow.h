#ifndef STAFFWORKFLOW_H
#define STAFFWORKFLOW_H
#include<string>

class StaffWorkFlow{//abstract class
    protected:
                std::string staffName;
                void clockIn();
                void clockOut();
                void takeBreak();
                virtual void performMainTask() = 0;
    public:
                std::string getName();
                virtual std::string getType() = 0;
                virtual void displayRoles() = 0;
                void executeWorkDay();
                virtual ~StaffWorkFlow();

};
#endif