#include "StaffWorkFlow.h"
#include <iostream>

std::string StaffWorkFlow::getName() const {
    return staffName;
}

StaffWorkFlow::~StaffWorkFlow(){}

void StaffWorkFlow::clockIn() {
    std::cout << staffName << " clocking in...\n";
}

void StaffWorkFlow::clockOut() {
    std::cout << staffName << " clocking out...\n";
}

void StaffWorkFlow::takeBreak() {
    std::cout << staffName << " taking lunch break\n";
}

void StaffWorkFlow::executeWorkDay() {
    clockIn();
    std::cout<<"\n ---Morning Shift---";
    performMorningTasks();  // Morning work
    takeBreak();
    std::cout<<"\n ---Afternoon Shift---";
    performAfternoonTasks();  // Afternoon work
    clockOut();
}

