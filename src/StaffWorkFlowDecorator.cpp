#include "StaffWorkFlowDecorator.h"

StaffWorkFlowDecorator::StaffWorkFlowDecorator(StaffWorkFlow* staff) {
  wrappedStaff = staff;
}

void StaffWorkFlowDecorator::performMorningTasks() {
  if (wrappedStaff)
    wrappedStaff->performMorningTasks();
}

void StaffWorkFlowDecorator::performAfternoonTasks() {
  if (wrappedStaff)
    wrappedStaff->performAfternoonTasks();
}

StaffWorkFlowDecorator::~StaffWorkFlowDecorator(){
	delete wrappedStaff;
}

std::string StaffWorkFlowDecorator::getName() const{
    return wrappedStaff->getName();
}

void StaffWorkFlowDecorator::displayRoles(){
  if(wrappedStaff)
  {
    wrappedStaff->displayRoles();
  }
}

std::string StaffWorkFlowDecorator::getType(){
  if(wrappedStaff){
    return wrappedStaff->getType();
  }
  return "Unknown Type";
}
