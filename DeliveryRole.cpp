#include "DeliveryRole.h"

DeliveryRole::DeliveryRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void DeliveryRole::performMainTask(){
    std::cout<<"Delivers plants to customers\n";
    StaffWorkFlowDecorator::performMainTask();
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