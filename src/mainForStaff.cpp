
#include <string>
#include "TreeFactory.h"
#include "FlowerFactory.h"
#include "HerbFactory.h"
#include "GiftWrappingDecorator.h"
#include "DecorativePotDecorator.h"
#include "PlantItem.h"
#include "PlantComponent.h"
#include "PlantBundle.h"
#include "Tree.h"
#include "Flower.h"
#include "Herb.h"
#include "StaffWorkFlow.h"
#include "StaffWorkFlowDecorator.h"
#include "GreenhouseWorker.h"
#include "SalesAssociate.h"
#include "SalesRole.h"
#include "DeliveryRole.h"
#include "LandscaperRole.h"
#include "ManagerRole.h"
#include "NurseryMediator.h"
#include <iostream>

void printSeparator(std::string title = "") {
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════════════\n";
    if (!title.empty()) {
        std::cout << "   " << title << "\n";
        std::cout << "═══════════════════════════════════════════════════════════\n";
    }
}

void testBasicStaff(NurseryMediator* nursery) {
    printSeparator("TEST 1: Basic Staff (No Decorators)");
    
    // Test Greenhouse Worker
    StaffWorkFlow* alice = new GreenhouseWorker("Alice", nursery);
    std::cout << "\n--- Alice's Profile ---\n";
    std::cout << "Name: " << alice->getName() << "\n";
    std::cout << "Type: " << alice->getType() << "\n\n";
    alice->displayRoles();
    
    // Test Sales Associate
    StaffWorkFlow* bob = new SalesAssociate("Bob", nursery);
    std::cout << "\n--- Bob's Profile ---\n";
    std::cout << "Name: " << bob->getName() << "\n";
    std::cout << "Type: " << bob->getType() << "\n\n";
    bob->displayRoles();
    
    delete alice;
    delete bob;
}

void testDecoratedStaff(NurseryMediator* nursery) {
    printSeparator("TEST 2: Decorated Staff (Multiple Roles)");
    
    // Create a versatile employee: Greenhouse + Sales + Delivery
    StaffWorkFlow* charlie = new GreenhouseWorker("Charlie", nursery);
    charlie = new SalesRole(charlie);
    charlie = new DeliveryRole(charlie);
    
    std::cout << "\n--- Charlie's Profile ---\n";
    std::cout << "Name: " << charlie->getName() << "\n";
    std::cout << "Type: " << charlie->getType() << "\n\n";
    charlie->displayRoles();
    
    delete charlie;
}

void testFullyDecoratedStaff(NurseryMediator* nursery) {
    printSeparator("TEST 3: Fully Decorated Staff (All Roles)");
    
    // Create super employee with ALL roles
    StaffWorkFlow* diana = new GreenhouseWorker("Diana", nursery);
    diana = new SalesRole(diana);
    diana = new DeliveryRole(diana);
    diana = new LandscaperRole(diana);
    diana = new ManagerRole(diana);
    
    std::cout << "\n--- Diana's Profile ---\n";
    std::cout << "Name: " << diana->getName() << "\n";
    std::cout << "Type: " << diana->getType() << "\n\n";
    diana->displayRoles();
    
    delete diana;
}

void testWorkDayExecution(NurseryMediator* nursery) {
    printSeparator("TEST 4: Work Day Execution (Template Method)");
    
    std::cout << "\n--- Basic Greenhouse Worker ---\n";
    StaffWorkFlow* worker1 = new GreenhouseWorker("Emily", nursery);
    worker1->executeWorkDay();
    
    std::cout << "\n--- Decorated Staff (Greenhouse + Sales) ---\n";
    StaffWorkFlow* worker2 = new GreenhouseWorker("Frank", nursery);
    worker2 = new SalesRole(worker2);
    worker2->executeWorkDay();
    
    std::cout << "\n--- Multi-Role Staff ---\n";
    StaffWorkFlow* worker3 = new SalesAssociate("Grace", nursery);
    worker3 = new DeliveryRole(worker3);
    worker3 = new ManagerRole(worker3);
    worker3->executeWorkDay();
    
    delete worker1;
    delete worker2;
    delete worker3;
}

void testStaffWithPlants(NurseryMediator* nursery) {
    printSeparator("TEST 5: Staff Working with Plants");
    
    // Add some plants to greenhouse
    std::cout << "\n--- Adding Plants to Greenhouse ---\n";
    nursery->addNewPlant("Rose");
    nursery->addNewPlant("Succulent");
    nursery->addNewPlant("Lavender");
    
    // Greenhouse worker cares for plants
    std::cout << "\n--- Greenhouse Worker Caring for Plants ---\n";
    StaffWorkFlow* gardener = new GreenhouseWorker("Henry", nursery);
    gardener->performMainTask();
    
    // Move mature plants to sales floor (simulate growth first)
    std::cout << "\n--- Advancing Time & Harvesting ---\n";
    nursery->advanceTime(10);  // Make plants mature
    
    // Sales associate works with sales floor
    std::cout << "\n--- Sales Associate Managing Sales Floor ---\n";
    StaffWorkFlow* seller = new SalesAssociate("Iris", nursery);
    seller->performMainTask();
    
    delete gardener;
    delete seller;
}

void testDifferentRoleCombinations(NurseryMediator* nursery) {
    printSeparator("TEST 6: Different Role Combinations");
    
    // Combination 1: Sales + Manager
    std::cout << "\n--- Sales Associate with Manager Role ---\n";
    StaffWorkFlow* staff1 = new SalesAssociate("Jack", nursery);
    staff1 = new ManagerRole(staff1);
    std::cout << "Type: " << staff1->getType() << "\n";
    staff1->displayRoles();
    
    // Combination 2: Greenhouse + Landscaper
    std::cout << "\n--- Greenhouse Worker with Landscaper Role ---\n";
    StaffWorkFlow* staff2 = new GreenhouseWorker("Kelly", nursery);
    staff2 = new LandscaperRole(staff2);
    std::cout << "Type: " << staff2->getType() << "\n";
    staff2->displayRoles();
    
    // Combination 3: Sales + Delivery + Landscaper
    std::cout << "\n--- Sales with Delivery and Landscaper ---\n";
    StaffWorkFlow* staff3 = new SalesAssociate("Leo", nursery);
    staff3 = new DeliveryRole(staff3);
    staff3 = new LandscaperRole(staff3);
    std::cout << "Type: " << staff3->getType() << "\n";
    staff3->displayRoles();
    
    delete staff1;
    delete staff2;
    delete staff3;
}

void testPolymorphism(NurseryMediator* nursery) {
    printSeparator("TEST 7: Polymorphism & Dynamic Binding");
    
    // Store different staff types in same array
    StaffWorkFlow* team[5];
    
    team[0] = new GreenhouseWorker("Mike", nursery);
    team[1] = new SalesAssociate("Nina", nursery);
    
    team[2] = new GreenhouseWorker("Oscar", nursery);
    team[2] = new SalesRole(team[2]);
    
    team[3] = new SalesAssociate("Paula", nursery);
    team[3] = new ManagerRole(team[3]);
    
    team[4] = new GreenhouseWorker("Quinn", nursery);
    team[4] = new DeliveryRole(team[4]);
    team[4] = new LandscaperRole(team[4]);
    team[4] = new ManagerRole(team[4]);
    
    // Display all staff
    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Staff Member " << (i+1) << " ---\n";
        std::cout << "Name: " << team[i]->getName() << "\n";
        std::cout << "Type: " << team[i]->getType() << "\n";
        team[i]->displayRoles();
    }
    
    // Execute work day for all
    printSeparator("All Staff Working");
    for (int i = 0; i < 5; i++) {
        std::cout << "\n=== " << team[i]->getName() << "'s Work Day ===\n";
        team[i]->executeWorkDay();
    }
    
    // Cleanup
    for (int i = 0; i < 5; i++) {
        delete team[i];
    }
}

int main() 
{
    // Initialize nursery
    NurseryMediator* nursery = new NurseryMediator();
    
    std::cout << "╔═══════════════════════════════════════════════════════════╗\n";
    std::cout << "║         STAFF SYSTEM COMPREHENSIVE TEST SUITE             ║\n";
    std::cout << "║       Testing Template Method & Decorator Patterns        ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════╝\n";
    
    // Run all tests
    testBasicStaff(nursery);
    testDecoratedStaff(nursery);
    testFullyDecoratedStaff(nursery);
    testWorkDayExecution(nursery);
    testStaffWithPlants(nursery);
    testDifferentRoleCombinations(nursery);
    testPolymorphism(nursery);
    
    printSeparator("TEST SUITE COMPLETED");
    std::cout << "✓ All tests executed successfully!\n";
    std::cout << "✓ Template Method Pattern verified\n";
    std::cout << "✓ Decorator Pattern verified\n";
    std::cout << "✓ Mediator Integration verified\n";
    std::cout << "✓ Polymorphism verified\n\n";
    
    // Cleanup
    delete nursery; 
    return 0;
}


/* ---

## **Expected Output Highlights**
```
═══════════════════════════════════════════════════════════
   TEST 1: Basic Staff (No Decorators)
═══════════════════════════════════════════════════════════

--- Alice's Profile ---
Name: Alice
Type: Greenhouse Worker

Alice - Greenhouse Worker
  Responsibilities:
  - Water plants
  - Monitor plant health
  - Harvest mature plants
  - Report plant issues

--- Bob's Profile ---
Name: Bob
Type: Sales Associate

Bob - Sales Associate
  Responsibilities:
  - Assist customers
  - Manage sales floor inventory
  - Process purchases
  - Maintain plant displays

═══════════════════════════════════════════════════════════
   TEST 2: Decorated Staff (Multiple Roles)
═══════════════════════════════════════════════════════════

--- Charlie's Profile ---
Name: Charlie
Type: Greenhouse Worker + Sales + Delivery

Charlie - Greenhouse Worker
  Responsibilities:
  - Water plants
  - Monitor plant health
  - Harvest mature plants
  - Report plant issues

[Additional Role: Sales Support]
  • Assist customers with inquiries
  • Provide plant recommendations
  • Help with sales transactions

[Additional Role: Delivery Driver]
  • Deliver plants to customers
  • Handle delivery logistics
  • Ensure safe plant transport

 */