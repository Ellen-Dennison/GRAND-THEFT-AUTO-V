#include "ManagerRole.h"
#include <iostream>

ManagerRole::ManagerRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void ManagerRole::performMorningTasks(){
    std::cout<<"Managing the other workers...\n";
    StaffWorkFlowDecorator::performMorningTasks();
}

void ManagerRole::performAfternoonTasks(){
    std::cout<<"Managing the other workers...\n";
    StaffWorkFlowDecorator::performAfternoonTasks();
}

std::string ManagerRole::getType() {
    return wrappedStaff->getType() + " + Manager";
}

void ManagerRole::displayRoles() {
    wrappedStaff->displayRoles();
    std::cout << "\n[Additional Role: Manager]\n";
    std::cout << "  • Supervise staff members\n";
    std::cout << "  • Coordinate daily operations\n";
    std::cout << "  • Handle administrative tasks\n";
    std::cout << "  • Make strategic decisions\n";
}
