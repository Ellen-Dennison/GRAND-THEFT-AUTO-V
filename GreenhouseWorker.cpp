#include "GreenhouseWorker.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include <iostream>

GreenhouseWorker::GreenhouseWorker(std::string name, NurseryMediator* med) {
    staffName = name;
    mediator = med;  // Store mediator reference
}

void GreenhouseWorker::performMainTask() {
    std::cout << staffName << " caring for greenhouse plants\n";
    
    // Ask mediator for greenhouse access
    std::vector<Plant*> greenhousePlants = mediator->getGreenhousePlants();
    
    if (greenhousePlants.empty()) {
        std::cout << "  No plants in greenhouse\n";
        return;
    }
    
    std::cout << "  Caring for " << greenhousePlants.size() << " plants\n";
    
    // Loop through plants
    for (Plant* plant : greenhousePlants) {
        // Water the plant
        plant->water();
        
        // Check health
        if (plant->getHealth() < 30) {
            std::cout << " WARNING: " << plant->getName() 
                      << " is wilting! Health: " << plant->getHealth() << "%\n";
            // Could notify mediator about wilting plant
            mediator->reportWiltingPlant(plant);
        }
        
        // Check if ready for sale
        if (plant->isReadyForSale()) {
            std::cout << "  ✓ " << plant->getName() 
                      << " is mature and ready for harvest\n";
        }
    }
    
    // Check for mature plants to harvest (via mediator)
    mediator->harvestMaturePlants();
}

std::string GreenhouseWorker::getType() {
    return "Greenhouse Worker";
}

void GreenhouseWorker::displayRoles() {
    std::cout << staffName << " - " << getType() << "\n";
    std::cout << "  Responsibilities:\n";
    std::cout << "  - Water plants\n";
    std::cout << "  - Monitor plant health\n";
    std::cout << "  - Harvest mature plants\n";
    std::cout << "  - Report plant issues\n";
}