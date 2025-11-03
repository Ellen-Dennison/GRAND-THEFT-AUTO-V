#include "LandscaperRole.h"
#include <iostream>

LandscaperRole::LandscaperRole(StaffWorkFlow* staff)
             : StaffWorkFlowDecorator(staff){}


void LandscaperRole::performMorningTasks(){
    std::cout<<"Performs ongoing morning tasks to keep landscapes healthy and attractive\n";
    StaffWorkFlowDecorator::performMorningTasks();
}

void LandscaperRole::performAfternoonTasks(){
    std::cout<<"Performs ongoing afternoon tasks to keep landscapes healthy and attractive\n";
    StaffWorkFlowDecorator::performAfternoonTasks();
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
