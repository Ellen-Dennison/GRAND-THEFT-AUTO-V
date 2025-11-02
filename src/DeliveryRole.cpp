#include "DeliveryRole.h"
#include <iostream>

DeliveryRole::DeliveryRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void DeliveryRole::performMorningTasks(){
    std::cout<<"Delivering plants to customers...\n";
    StaffWorkFlowDecorator::performMorningTasks();
}

void DeliveryRole::performAfternoonTasks(){
    std::cout<<"Delivering plants to customers...\n";
    StaffWorkFlowDecorator::performAfternoonTasks();
}

std::string DeliveryRole::getType() {
    return wrappedStaff->getType() + " + Delivery";
}

void DeliveryRole::displayRoles() {
    wrappedStaff->displayRoles();
    std::cout << "\n[Additional Role: Delivery Driver]\n";
    std::cout << "  • Deliver plants to customers\n";
    std::cout << "  • Handle delivery logistics\n";
    std::cout << "  • Ensure safe plant transport\n";
}
