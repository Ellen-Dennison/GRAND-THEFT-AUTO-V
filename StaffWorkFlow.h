#ifndef STAFFWOORKFLOW_H
#define STAFFWORKFLOW_H
#include<string>

class StaffWorkFlow{
    private:
           std::string name;
    public:
            void executeWorkDay();
            virtual void printStaff() = 0;
};
#endif