#include "GreenhouseWorker.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include <iostream>

GreenhouseWorker::GreenhouseWorker(std::string name, NurseryMediator* med) {
    staffName = name;
    mediator = med;  // Store mediator reference
}

void GreenhouseWorker::performMorningTasks() {
    std::cout << staffName << " is starting morning greenhouse care\n";
    
    // Ask mediator for greenhouse access
    std::vector<Plant*> greenhousePlants = mediator->getGreenhouse();
    
    if (greenhousePlants.empty()) {
        std::cout << "  No plants in greenhouse\n";
        return;
    }
    
    std::cout << "Morning: Watering" << greenhousePlants.size() << " plants\n";

    int wateredCount = 0;
    for (Plant* plant : greenhousePlants) {
        plant->water();
        wateredCount++;
    }
    
    std::cout << "  ✓ Watered " << wateredCount << " plants\n";
    
    //Check wilting plants. Mediator??
    // Loop through plants
    for (Plant* plant : greenhousePlants) {
        
        // Check health
        if (plant->getHealth() < 30) {
            std::cout << " WARNING: " << plant->getName() 
                      << " is wilting! Health: " << plant->getHealth() << "%\n";
            // Could notify mediator about wilting plant
            //mediator->checkForWiltingPlants();//!compiler gives errors for this check if I changed to right function
        }
    }
}

void GreenhouseWorker::performAfternoonTasks(){
    std::cout<< staffName<<" is starting afternoon greenhouse duties\n";

    std::vector<Plant*> greenhousePlants = mediator->getGreenhouse();

    if(greenhousePlants.empty()){
        std::cout<<"No plants in greenhouse\n";
        return;
    }

    std::cout<<"Afternoon: Providing sunlight and fertilizer\n";

    for(Plant* plant : greenhousePlants){
        plant->provideSunlight();
        plant->fertilize();
    }

    std::cout<<"Harvest Time!\n";
    mediator->harvestMaturePlants();

    std::cout<<"Final health check...\n";
    mediator->checkForWiltingPlants();
}

std::string GreenhouseWorker::getType() {
    return "Greenhouse Worker";
}

void GreenhouseWorker::displayRoles() {
    std::cout << staffName << " - " << getType() << "\n";
    std::cout << "  Morning Responsibilities:\n";
    std::cout << "  - Water plants\n";
    std::cout << "  - Check for plants in critical health condition\n";
    std::cout << "  Afternoon Responsibilities:\n";
    std::cout << "  - Provide appropriate amount of sunlight\n";
    std::cout << "  - Harvest mature plants\n";
    std::cout << "  - Monitor overall health\n";
}
