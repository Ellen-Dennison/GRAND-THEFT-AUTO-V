#include "doctest.h"
#include "../src/StaffWorkFlow.h"
#include "../src/GreenhouseWorker.h"
#include "../src/SalesAssociate.h"
#include "../src/StaffWorkFlowDecorator.h"
#include "../src/ManagerRole.h"
#include"../src/LandscaperRole.h"
#include"../src/SalesRole.h"
#include"../src/DeliveryRole.h"
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

TEST_CASE("Testing the basic staff")
{   
  void testBasicStaff(NurseryMediator* nursery) {
    printSeparator("TEST 1: Basic Staff (No Decorators)");
    
    // Test Greenhouse Worker
    StaffWorkFlow* alice = new GreenhouseWorker("Alice", nursery);
    CHECK(alice->getName() == "Alice");
    CHECK(alice->getType() = "Greenhouse Worker");

    // Test Sales Associate
    StaffWorkFlow* bob = new SalesAssociate("Bob", nursery);
    CHECK(bob->getName() == "Bob");
    CHECK(bob->getType() == "Sales Associate");
    
    delete alice;
    delete bob;
  }

}

TEST_CASE("Testing the decorated staff (Multiple Roles)")
{
   void testDecoratedStaff(NurseryMediator* nursery) {
    // Create a versatile employee: Greenhouse + Sales + Delivery
    StaffWorkFlow* charlie = new GreenhouseWorker("Charlie", nursery);
    CHECK(charlie->getName() == "Charlie");
    CHECK(charlie->getType() == "Greenhouse Worker");

    charlie = new SalesRole(charlie);
    CHECK(charlie->getType() == "Greenhouse Worker Sales");

    charlie = new DeliveryRole(charlie);
    CHECK(charlie->getType() == "Greenhouse Worker Sales Delivery");

    delete charlie;
   }
}

TEST_CASE("Testing fully decorated staff (All Roles)"){
    void testFullyDecoratedStaff(NurseryMediator* nursery) {
    
    // Create super employee with ALL roles
    StaffWorkFlow* diana = new GreenhouseWorker("Diana", nursery);
    CHECK(diana->getName() == "Diana");
    CHECK(diana->getType() = "Greenhouse Worker");

    diana = new SalesRole(diana);
    CHECK(diana->getType() = "Greenhouse Worker Sales");

    diana = new DeliveryRole(diana);
    CHECK(diana->getType() = "Greenhouse Worker Sales Delivery");

    diana = new LandscaperRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker Sales Delivery Landscaper");

    diana = new ManagerRole(diana);
    CHECK(diana->getType() == "Greenhouse Worker Sales Delivery Landscaper Manager");
    
    delete diana;
    }
}

TEST_CASE("Testing work day execution (Template Method)"){
  void testWorkDayExecution(NurseryMediator* nursery) {
    
    StaffWorkFlow* worker1 = new GreenhouseWorker("Emily", nursery);
    CHECK(worker1->getName() == "Emily");
    CHECK(worker1->getType() == "Greenhouse Worker");
    
    std::cout << "\n--- Decorated Staff (Greenhouse + Sales) ---\n";
    StaffWorkFlow* worker2 = new GreenhouseWorker("Frank", nursery);
    worker2 = new SalesRole(worker2);
    CHECK(worker2->getName() ==  "Frank");
    CHECK(worker2->getType() == "GreenhouseWorker Sales");
    
    std::cout << "\n--- Multi-Role Staff ---\n";
    StaffWorkFlow* worker3 = new SalesAssociate("Grace", nursery);
    worker3 = new DeliveryRole(worker3);
    worker3 = new ManagerRole(worker3);
    CHECK(worker3->getName() == "Grace");
    CHECK(worker3->getType() == "Sales Associate Delivery Manager");

    delete worker1;
    delete worker2;
    delete worker3;
  }
}

TEST_CASE("Testing staff working with plants"){
  void testStaffWithPlants(NurseryMediator* nursery){
    
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
}





