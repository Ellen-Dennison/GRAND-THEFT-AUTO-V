

#ifndef GRAND_THEFT_AUTO_V_ADVANCETIMECOMMAND_H
#define GRAND_THEFT_AUTO_V_ADVANCETIMECOMMAND_H
#include "Command.h"
#include <vector>

class Plant;

class AdvanceTimeCommand : public Command{
private:
    std::vector<Plant*>* greenhouse;
    int weeks;

public:
    AdvanceTimeCommand(std::vector<Plant*>* plants, int numWeeks);
    void execute() override;



};


#endif //GRAND_THEFT_AUTO_V_ADVANCETIMECOMMAND_H
