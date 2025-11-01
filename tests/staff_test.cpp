#include "doctest.h"
#include "../src/StaffWorkFlow.h"
#include "../src/GreenhouseWorker.h"
#include "../src/SalesAssociate.h"
#include "../src/StaffWorkFlowDecorator.h"
#include "../src/ManagerRole.h"
#include"../src/LandscaperRole.h"
#include"../src/SalesRole.h"
#include"../src/DeliveryRole.h"
#include"../src/NurseryMediator.h"
#include "../src/Plant.h"
#include "../src/PlantFactory.h"
#include "../src/PlantCaretaker.h"
#include "../src/Customer.h"
#include "../src/PlantOrder.h"
#include <vector>
#include <iostream>
#include <string>

// Helper function
void printSeparator(const std::string& message) {
    std::cout << "\n=== " << message << " ===\n";
}

TEST_CASE("Testing the basic staff")
{   
    printSeparator("TEST 1: Basic Staff (No Decorators)");
    NurseryMediator *nursery = new NurseryMediator();

    // Test Greenhouse Worker
    StaffWorkFlow* alice = new GreenhouseWorker("Alice", nursery);
    CHECK(alice->getName() == "Alice");
    CHECK(alice->getType() == "Greenhouse Worker");

    // Test Sales Associate
    StaffWorkFlow* bob = new SalesAssociate("Bob", nursery);
    CHECK(bob->getName() == "Bob");
    CHECK(bob->getType() == "Sales Associate");
    
    delete nursery;
    delete alice;
    delete bob;
}

TEST_CASE("Testing the decorated staff (Multiple Roles)")
{
    // Create a versatile employee: Greenhouse + Sales + Delivery
    NurseryMediator *nursery = new NurseryMediator();
    StaffWorkFlow* charlie = new GreenhouseWorker("Charlie", nursery);
    CHECK(charlie->getName() == "Charlie");
    CHECK(charlie->getType() == "Greenhouse Worker");

    charlie = new SalesRole(charlie);
    CHECK(charlie->getType() == "Greenhouse Worker + Sales");

    charlie = new DeliveryRole(charlie);
    CHECK(charlie->getType() == "Greenhouse Worker + Sales + Delivery");

    delete nursery;
    delete charlie;
}

TEST_CASE("Testing fully decorated staff (All Roles)"){
    NurseryMediator *nursery = new NurseryMediator();
    
    // Create super employee with ALL roles
    StaffWorkFlow* diana = new GreenhouseWorker("Diana", nursery);
    CHECK(diana->getName() == "Diana");
    CHECK(diana->getType() == "Greenhouse Worker");

    diana = new SalesRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker + Sales");

    diana = new DeliveryRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker + Sales + Delivery");

    diana = new LandscaperRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker + Sales + Delivery + Landscaper");

    diana = new ManagerRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker + Sales + Delivery + Landscaper + Manager");
    
    delete diana;
    delete nursery;
}

TEST_CASE("Testing work day execution (Template Method)"){
    NurseryMediator *nursery = new NurseryMediator();
    StaffWorkFlow* worker1 = new GreenhouseWorker("Emily", nursery);
    CHECK(worker1->getName() == "Emily");
    CHECK(worker1->getType() == "Greenhouse Worker");
    
    std::cout << "\n--- Decorated Staff (Greenhouse + Sales) ---\n";
    StaffWorkFlow* worker2 = new GreenhouseWorker("Frank", nursery);
    worker2 = new SalesRole(worker2);
    CHECK(worker2->getName() == "Frank");
    CHECK(worker2->getType() == "Greenhouse Worker + Sales");
    
    std::cout << "\n--- Multi-Role Staff ---\n";
    StaffWorkFlow* worker3 = new SalesAssociate("Grace", nursery);
    worker3 = new DeliveryRole(worker3);
    worker3 = new ManagerRole(worker3);
    CHECK(worker3->getName() == "Grace");
    CHECK(worker3->getType() == "Sales Associate + Delivery + Manager");

    delete nursery;
    delete worker1;
    delete worker2;
    delete worker3;
}