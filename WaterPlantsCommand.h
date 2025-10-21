
#ifndef GRAND_THEFT_AUTO_V_WATERPLANTSCOMMAND_H
#define GRAND_THEFT_AUTO_V_WATERPLANTSCOMMAND_H
#include "Command.h"
#include <vector>

class Plant;

class WaterPlantsCommand : public Command{
private:
    std::vector<Plant*>* greenhouse;

public:
    WaterPlantsCommand(std::vector<Plant*>* plants);
    void execute() override;



};


#endif //GRAND_THEFT_AUTO_V_WATERPLANTSCOMMAND_H
