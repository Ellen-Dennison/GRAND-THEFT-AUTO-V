
#include "GreenhouseWorker.h"
#include <iostream>

GreenhouseWorker::GreenhouseWorker(const std::string& n, NurseryMediator* m) : StaffWorkflow(n, m){

}

void GreenhouseWorker::performMainTask() {
    std::cout << staffName << " is caring for plants in greenhouse" << std::endl;
}