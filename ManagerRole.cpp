#include "ManagerRole.h"

ManagerRole::ManagerRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void ManagerRole::performMainTask(){
    std::cout<<"Manages the other workers\n";
    StaffWorkFlowDecorator::performMainTask();
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