
#include "SalesAssociate.h"
#include <iostream>

SalesAssociate::SalesAssociate(const std::string &n, NurseryMediator *m)  : StaffWorkflow(n, m){

}

void SalesAssociate::performMainTask() {
    std::cout << staffName << " is assisting customers on sales floor" << std::endl;
}