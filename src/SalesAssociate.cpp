#include "SalesAssociate.h"
#include "NurseryMediator.h"
#include "Plant.h"
#include "Customer.h"
#include <iostream>

SalesAssociate::SalesAssociate(std::string name, NurseryMediator* med) {
    staffName = name;
    mediator = med;
}

void SalesAssociate::executeWorkDay() {
    clockIn();
    std::cout << "\n ---Morning Shift---\n";
    performMorningTasks();
    takeBreak();
    std::cout << "\n ---Afternoon Shift---\n";
    performAfternoonTasks();
    std::cout << "  " << staffName << " remaining on duty for customer service\n";
}

void SalesAssociate::performMorningTasks() {
    std::cout << staffName << " is preparing for customer service\n";
    
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    std::cout << "  Morning: Reviewing inventory for customers\n";
    
    if (salesFloor.empty()) {
        std::cout << "  No plants available for sale\n";
        std::cout << "  Waiting for stock...\n";
        return;
    }
    
    std::cout << "  Available plants: " << salesFloor.size() << "\n";
    
    // Organize by plant type for easy customer assistance
    std::map<std::string, int> plantsByType;
    for (Plant* plant : salesFloor) {
        plantsByType[plant->getType()]++;
    }
    
    std::cout << "  Today's inventory by category:\n";
    for (const auto& pair : plantsByType) {
        std::cout << "    - " << pair.second << " " << pair.first << "(s)\n";
    }
}

void SalesAssociate::performAfternoonTasks() {
    std::cout << staffName << " ready for afternoon customer service\n";
    
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    if (salesFloor.empty()) {
        std::cout << "  No plants available for customers\n";
        return;
    }
    
    std::cout << "  Afternoon: Available for customer assistance\n";
    std::cout << "  Plants in stock: " << salesFloor.size() << "\n";
    
    // Review featured plants
    std::cout << "  Featured plants:\n";
    int featuredCount = 0;
    for (Plant* plant : salesFloor) {
        if (plant->getHealth() >= 90) {
            std::cout << plant->getName() 
                      << " (" << plant->getType() << ")"
                      << " - R" << plant->getPrice()
                      << " [Premium Health: " << plant->getHealth() << "%]\n";
            featuredCount++;
        }
    }
    
    if (featuredCount == 0) {
        std::cout << "    All plants are in good condition and ready for sale\n";
    }
}

void SalesAssociate::assistCustomer(Customer* customer) {
    std::cout << staffName << " assisting " << customer->getName() << "\n";
    
    // Get sales floor through mediator
    std::vector<Plant*> salesFloor = mediator->getSalesFloor();
    
    //std::string preference = customer->getPreferredPlantType();//!function not implemented
    //std::string preference = "empty";
    double budget = customer->getBudget();
    
    std::cout << "'" << customer->getName() << ", what brings you in today?'\n";
    std::cout << "'We have a wonderful selection within your budget of R" << budget << "'\n";
    
    //Show affordable plants by category
    std::map<std::string, int> affordableByType;
    
    for (Plant* plant : salesFloor) {
        if (customer->canAfford(plant->getPrice())) {
            affordableByType[plant->getType()]++;
        }
    }
    
    if (!affordableByType.empty()) {
        std::cout << "  \nAvailable in your budget:\n";
        for (const auto& pair : affordableByType) {
            std::cout << pair.second << " " << pair.first 
                      << "(s) available\n\n";
        }
    } else {
        std::cout << "  Unfortunately, our current selection exceeds your budget.\n";
    }
}


void SalesAssociate::endShift() {
    clockOut();
}

std::string SalesAssociate::getType() {
    return "Sales Associate";
}

void SalesAssociate::displayRoles() {
    std::cout << staffName << " - " << getType() << "\n";
    std::cout << "  Morning Responsibilities:\n";
    std::cout << "    - Review inventory\n";
    std::cout << "    - Prepare for customer interactions\n";
    std::cout << "    - Organize product knowledge\n";
    std::cout << "  Afternoon Responsibilities:\n";
    std::cout << "    - Assist customers with purchases\n";
    std::cout << "    - Provide plant recommendations\n";
    std::cout << "    - Answer customer questions\n";
    std::cout << "    - Process sales transactions\n";
}
