#include "StaffWorkFlowDecorator.h"

StaffWorkFlowDecorator::StaffWorkFlowDecorator(StaffWorkFlow* staff) {
  wrappedStaff = staff;
}

void StaffWorkFlowDecorator::performMainTask() {
  if (wrappedStaff)
    wrappedStaff->performMainTask();
}

StaffWorkFlowDecorator::~StaffWorkFlowDecorator(){
	delete wrappedStaff;
}

std::string StaffWorkFlowDecorator::getName(){
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
