#include "SalesFloorWorker.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include <iostream>

SalesFloorWorker::SalesFloorWorker(std::string name, NurseryMediator* med) {
    staffName = name;
    mediator = med;
}

void SalesFloorWorker::performMorningTasks() {
    std::cout << staffName << " is starting morning sales floor maintenance\n";
    
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    if (salesFloor.empty()) {
        std::cout << "  No plants on sales floor\n";
        std::cout << "  Requesting stock from greenhouse...\n";
        mediator->harvestMaturePlants();
        return;
    }
    
    std::cout << "  Morning: Setting up displays\n";
    std::cout << "  Available plants: " << salesFloor.size() << "\n";
    
    std::cout << "  Watering display plants...\n";
    for (Plant* plant : salesFloor) {
        plant->water();
    }
    
    std::cout << "  Morning watering routine completed\n";
}

void SalesFloorWorker::performAfternoonTasks() {
    std::cout << staffName << " managing afternoon sales floor care\n";
    
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    if (salesFloor.empty()) {
        std::cout << "  Sales floor is empty\n";
        std::cout << "  Restocking from greenhouse...\n";
        mediator->harvestMaturePlants();
        return;
    }
    
    std::cout << "  Afternoon: Plant maintenance\n";
    
    for (Plant* plant : salesFloor) {
        plant->provideSunlight();
    }
    
    for (Plant* plant : salesFloor) {
        plant->fertilize();
    }
    
    // Check for low stock
    if (salesFloor.size() < 5) {
        std::cout << "  LOW STOCK ALERT!\n";
        mediator->harvestMaturePlants();
    }
}

std::string SalesFloorWorker::getType() {
    return "Sales Floor Worker";
}

void SalesFloorWorker::displayRoles() {
    std::cout << staffName << " - " << getType() << "\n";
    std::cout << "  Morning Responsibilities:\n";
    std::cout << "    - Open and set up sales floor\n";
    std::cout << "    - Arrange plant displays\n";
    std::cout << "    - Water all display plants (respecting schedules)\n";
    std::cout << "    - Check plant health\n";
    std::cout << "  Afternoon Responsibilities:\n";
    std::cout << "    - Provide sunlight to plants\n";
    std::cout << "    - Fertilize plants in critical condition\n";
    std::cout << "    - Monitor stock levels\n";
    std::cout << "    - Maintain plant health on display\n";
    std::cout << "    - Restock as needed\n";
}
