
#ifndef GRAND_THEFT_AUTO_V_SALESASSOCIATE_H
#define GRAND_THEFT_AUTO_V_SALESASSOCIATE_H


#include "StaffWorkflow.h"

class SalesAssociate : public StaffWorkflow{
public:
    SalesAssociate(const std::string& n, NurseryMediator* m);
    void performMainTask() override;
};


#endif //GRAND_THEFT_AUTO_V_SALESASSOCIATE_H
