#include "LandscaperRole.h"
#include <iostream>

LandscaperRole::LandscaperRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void LandscaperRole::performMainTask(){
    std::cout<<"Performs ongoing tasks to keep landscapes healthy and attractive\n";
    StaffWorkFlowDecorator::performMainTask();
}

std::string LandscaperRole::getType() {
    return wrappedStaff->getType() + " + Landscaper";
}

void LandscaperRole::displayRoles() {
    wrappedStaff->displayRoles();
    std::cout << "\n[Additional Role: Landscaper]\n";
    std::cout << "  • Maintain outdoor displays\n";
    std::cout << "  • Design garden arrangements\n";
    std::cout << "  • Prune and shape plants\n";
    std::cout << "  • Keep landscapes attractive\n";
}