#include "WaterPlantsCommand.h"
#include <iostream>

WaterPlantsCommand::WaterPlantsCommand(std::vector<Plant*>& plantCollection) : plants(plantCollection) {

}
WaterPlantsCommand::~WaterPlantsCommand(){

}

void WaterPlantsCommand::execute() {
    if(plants.empty()) {
        std::cout << "No plants to water." << std::endl;
        return;
    }
    std::cout << "\n------ Watering Plants ------" << std::endl;
    std::cout << "Watering " << plants.size() << " plant (s)..." << std::endl;

    int wateredCount = 0;

    for(Plant* plant : plants) {
        if(plant != nullptr) {
            plant->water();
            wateredCount++;

        }else {
            std::cerr << "Warning: Encountered null pointer, skipping..." << std::endl;

        }
    }
    std::cout << "Successfully watered " << wateredCount << " plant(s)." << std::endl;
    std::cout << "===========================\n" << std::endl;
}

std::string WaterPlantsCommand::getDescription() const {
    return "Water " + std::to_string(plants.size()) +  " plant(s) in collection";
}

bool WaterPlantsCommand::isUndoable() const {
    return false;
}

int WaterPlantsCommand::getPlantCount() const{
    return static_cast<int>(plants.size());
}

