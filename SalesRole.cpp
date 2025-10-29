#include "SalesRole.h"
#include <iostream>

SalesRole::SalesRole(StaffWorkFlow* staff)
    : StaffWorkFlowDecorator(staff) {}

void SalesRole::performMainTask() {
    std::cout << "Assists customers on the sales floor\n";
    StaffWorkFlowDecorator::performMainTask();
}

std::string SalesRole::getType() {
    return wrappedStaff->getType() + " + Sales";
}

void SalesRole::displayRoles() {
    wrappedStaff->displayRoles();
    std::cout << "\n[Additional Role: Sales Support]\n";
    std::cout << "  • Assist customers with inquiries\n";
    std::cout << "  • Provide plant recommendations\n";
    std::cout << "  • Help with sales transactions\n";
}