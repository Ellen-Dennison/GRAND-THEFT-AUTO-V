
#ifndef GRAND_THEFT_AUTO_V_GREENHOUSEWORKER_H
#define GRAND_THEFT_AUTO_V_GREENHOUSEWORKER_H

#include "StaffWorkflow.h"

class GreenhouseWorker : public StaffWorkflow{
public:
    GreenhouseWorker(const std::string& n, NurseryMediator* m);
    void performMainTask() override;
};


#endif //GRAND_THEFT_AUTO_V_GREENHOUSEWORKER_H
