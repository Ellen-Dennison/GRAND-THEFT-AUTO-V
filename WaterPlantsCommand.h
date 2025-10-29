
#ifndef WATERPLANTSCOMMAND_H
#define WATERPLANTSCOMMAND_H
#include "Command.h"
#include "Plant.h"
#include <vector>
#include <string>



class WaterPlantsCommand : public Command{
private:
    std::vector<Plant*>& plants;

public:
    WaterPlantsCommand(std::vector<Plant*>& plantCollection);
    ~WaterPlantsCommand();

    void execute() override;

    std::string getDescription() const override;

    bool isUndoable() const override;

    int getPlantCount() const;



};


#endif //WATERPLANTSCOMMAND_H