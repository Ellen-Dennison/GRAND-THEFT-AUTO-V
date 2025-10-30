#include "StaffWorkFlow.h"
#include <iostream>

std::string StaffWorkFlow::getName(){
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
    performMainTask();  // Morning work
    takeBreak();
    performMainTask();  // Afternoon work
    clockOut();
}

