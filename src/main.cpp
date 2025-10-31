#include <iostream>
#include <vector>
#include<string>
#include <string>

#include "Plant.h"
#include "Flower.h"
#include "Herb.h"
#include "Succulent.h"
#include "Tree.h"
#include "PlantFactory.h"
#include "FlowerFactory.h"
#include "HerbFactory.h"
#include "SucculentFactory.h"
#include "TreeFactory.h"
#include "DecorativePotDecorator.h"
#include "GiftWrappingDecorator.h"
#include "PlantItem.h"
#include "PlantComponent.h"
#include "PlantBundle.h"
#include "StaffWorkFlow.h"
#include "StaffWorkFlowDecorator.h"
#include "GreenhouseWorker.h"
#include "SalesAssociate.h"
#include "SalesRole.h"
#include "DeliveryRole.h"
#include "LandscaperRole.h"
#include "ManagerRole.h"
#include "NurseryMediator.h"
#include "Customer.h"
#include "PlantCaretaker.h"
#include "PlantOrder.h"

#include "PlantMemento.h"
#include "PlantCaretaker.h"
#include "Subject.h"
#include "ManagerObserver.h"
#include "StaffObserver.h"
#include "Command.h"
#include "AdvanceTimeCommand.h"
#include "WaterPlantsCommand.h"
#include "RevivePlantCommand.h"
#include "NurseryMediator.h"
#include "StaffWorkFlow.h"
#include "StaffWorkFlowDecorator.h"
#include "LandscaperRole.h"
#include "DeliveryRole.h"
#include "SalesRole.h"
#include "ManagerRole.h"
#include "GreenhouseWorker.h"
#include "SalesAssociate.h"
#include "PlantOrder.h"
#include "Customer.h"
#include "PlantComponent.h"
#include "PlantItem.h"
#include "PlantBundle.h"

void printSeparator(const std::string& title) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(60, '=') << "\n" << std::endl;
}

void testCompleteNurseryWorkflow() 
{    
    std::cout << "🌿 WELCOME TO GRAND THEFT NURSERY 🌿\n" << std::endl;
    std::cout << "Simulating 3 months in the life of our nursery...\n" << std::endl;
    
    //Week 0: Setup
    std::cout<<"===WEEK 0: NURSERY SETUP & STAFF HIRING==="<<std::endl;
    
    NurseryMediator* nursery = new NurseryMediator();
    
    //Hire initial staff
    std::cout << "Hiring Initial Staff:\n" << std::endl;
    StaffWorkFlow* Kobe = new GreenhouseWorker("Kobe", nursery);
    StaffWorkFlow* Naledi = new SalesAssociate("Naledi", nursery);
    StaffWorkFlow* Trevor = new GreenhouseWorker("Trevor", nursery);
    
    Kobe->displayRoles();
    std::cout << std::endl;
    Naledi->displayRoles();
    std::cout << std::endl;
    Trevor->displayRoles();
    std::cout << std::endl;
    
    //Setup observer system
    Subject* notifSystem = new Subject();
    ManagerObserver* manager = new ManagerObserver("Sarah");
    StaffObserver* kobeObs = new StaffObserver("Kobe", "GreenhouseWorker");
    StaffObserver* nalediObs = new StaffObserver("Naledi", "SalesAssociate");
    
    notifSystem->attach(manager);
    notifSystem->attach(kobeObs);
    notifSystem->attach(nalediObs);
    
    std::cout << "\nNotification System Active!\n" << std::endl;
    notifSystem->notify("Nursery is now open for business!");
    
    //Week 1: plantations:
    std::cout<<"===WEEK 1: PLANTING SEASON BEGINS==="<<std::endl;
    
    std::cout << "Kobe's first day at work as a greenhouse worker - He plants new stock\n" << std::endl;
    Kobe->executeWorkDay();
    
    // Add diverse inventory
    std::cout << "\nReceiving New Plant Shipment:\n" << std::endl;
    nursery->addNewPlant("Flower");  // Rose
    nursery->addNewPlant("Flower");  // Tulip
    nursery->addNewPlant("Flower");  // Orchid
    nursery->addNewPlant("Herb");    // Basil
    nursery->addNewPlant("Herb");    // Rosemary
    nursery->addNewPlant("Succulent"); // Aloe
    nursery->addNewPlant("Succulent"); // Cactus
    nursery->addNewPlant("Tree");    // Oak
    
    notifSystem->notify("8 new plants added to greenhouse inventory");
    
    nursery->displayInventory();
    
    // Save healthy states for all plants
    std::cout << "\nSaving Healthy Plant States...\n" << std::endl;
    nursery->saveHealthyStates();
    std::cout<<std::endl;
    std::cout<<"Plant States Saved!"<<std::endl;

    //Week 9: Capitalism
    std::cout<<"===WEEK 9: SELLING PLANTS AND CUSTOMERS ARE READY TO BUY ITEMS==="<<std::endl;

    //comes in sets name and budget and asks for recommandations and see what plant are available
    Customer* guy = new Customer("Jack-Jack", 2000.00);
    guy->askForRecommendation();
    guy->browseSalesFloor(nursery->getGreenhouse());

    //customer wants to buy a plant now but the customer would like some customisation to their order too
    guy->expressInterest("Flower");
    guy->requestCustomisation("Pot-plant");
    //!decoarating the customers plant before final purchase
    
    //PlantDecorator* JackJackPlant = new DecorativePotDecorator(flower);
    //jackJackPlant->

    //combining the customer's multiple orders into one large order so the customer can finaly make the purchase
    //PlantComponent* JackJackitems = new PlantItem();
    //PlantComponent* finalOrder = new PlantBundle();
    //finalOrder->display()
    //guy->makePurchase(100.00);


    delete guy;
    //delete JackJackPlant;
    

}

//Testing Staff management
void printSeparator2(std::string title = "") {
    std::cout << "\n";
    std::cout << "═══════════════════════════════════════════════════════════\n";
    if (!title.empty()) {
        std::cout << "   " << title << "\n";
        std::cout << "═══════════════════════════════════════════════════════════\n";
    }
}

void testBasicStaff(NurseryMediator* nursery) {
    printSeparator2("TEST 1: Basic Staff (No Decorators)");
    
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
    printSeparator2("TEST 2: Decorated Staff (Multiple Roles)");
    
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
    printSeparator2("TEST 3: Fully Decorated Staff (All Roles)");
    
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
    printSeparator2("TEST 4: Work Day Execution (Template Method)");
    
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
    printSeparator2("TEST 5: Staff Working with Plants");
    
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
    printSeparator2("TEST 6: Different Role Combinations");
    
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
    printSeparator2("TEST 7: Polymorphism & Dynamic Binding");
    
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

int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║             PLANT NURSERY MANAGEMENT SYSTEM                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout <<"TESTING:\n"
              << "Plant Class Integration with Concrete Plants, Factories, States, Strategies and Plant Decorators";
    
    try {
        testVarietyOfPlants();
        testPriceComparison();
        testPlantGrowthCycle();
        testWateringStrategies();
        testSaleReadiness();
        testExpensiveVsCheapPlants();
        testDecorators();
        testCompleteNurserySimulation();

        //Testing the Staff Management System
        //Initialize nursery
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
        printSeparator("ALL TESTS COMPLETED SUCCESSFULLY");
        
    
    try {
        testCompleteNurseryWorkflow();
                
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
        return 1;
    }


    
        return 0;
}

