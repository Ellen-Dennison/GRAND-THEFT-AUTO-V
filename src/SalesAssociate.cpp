#include "SalesAssociate.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include "Customer.h"
#include <iostream>

SalesAssociate::SalesAssociate(std::string name, NurseryMediator* med) {
    staffName = name;
    mediator = med;  // Store mediator reference
}

void SalesAssociate::performMainTask() {
    std::cout << staffName << " working on the sales floor\n";
    
    //- Ask mediator for sales floor access
    std::vector<Plant*> salesFloor = mediator->getSalesFloorPlants();
    
    if (salesFloor.empty()) {
        std::cout << "  No plants on sales floor\n";
        std::cout << "  Requesting stock from greenhouse...\n";
        mediator->harvestMaturePlants();
        return;
    }
    
    // Check inventory
    std::cout << "  Available plants: " << salesFloor.size() << "\n";
    
    // Display available plants
    std::cout << "  Plants ready for sale:\n";
    for (Plant* plant : salesFloor) {
        std::cout << "    - " << plant->getName() 
                  << " (" << plant->getType() << ")"
                  << " - R" << plant->getPrice()
                  << " [Health: " << plant->getHealth() << "%]\n";
    }
    
    // Check for plants needing care on sales floor
    for (Plant* plant : salesFloor) {
        if (plant->getHealth() < 70) {
            std::cout << "Watering " << plant->getName() 
                      << " on display\n";
            plant->water();
        }
    }
    
    // Check for low stock
    if (salesFloor.size() < 5) {
        std::cout << "LOW STOCK ALERT!\n";
        std::cout << "  Requesting more plants from greenhouse...\n";
        mediator->harvestMaturePlants();
    }
}

void SalesAssociate::assistCustomer(Customer* customer) {
    std::cout << staffName << " assisting " << customer->getName() << "\n";
    
    // Get sales floor through mediator
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    std::string preference = customer->getPreferredPlantType();
    double budget = customer->getBudget();
    
    std::cout << "  Customer looking for: " << preference 
              << " (Budget: R" << budget << ")\n";
    
    // Show matching plants
    bool foundMatch = false;
    for (Plant* plant : salesFloor) {
        if (plant->getType() == preference && 
            customer->canAfford(plant->getPrice())) {
            std::cout << "  ✓ Recommending: " << plant->getName() 
                      << " - R" << plant->getPrice() << "\n";
            foundMatch = true;
        }
    }
    
    if (!foundMatch) {
        std::cout << "  No matching plants available in budget\n";
    }
}

std::string SalesAssociate::getType() {
    return "Sales Associate";
}

void SalesAssociate::displayRoles() {
    std::cout << staffName << " - " << getType() << "\n";
    std::cout << "  Responsibilities:\n";
    std::cout << "  - Assist customers\n";
    std::cout << "  - Manage sales floor inventory\n";
    std::cout << "  - Process purchases\n";
    std::cout << "  - Maintain plant displays\n";
}