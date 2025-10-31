#include <iostream>
#include <vector>
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
#include "PlantDecorator.h"
#include "DecorativePotDecorator.h"
#include "PlantItem.h"
#include "PlantBundle.h"

void testNurserySimulation() {    
    std::cout << "WELCOME TO GRAND THEFT NURSERY\n" << std::endl;
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

    //Week 2-4: Plant Growth Phase
    std::cout<<"===WEEKS 2-4:PLANT GROWTH & CARE PHASE==="<<std::endl;
    
    //PlantCaretaker* caretaker = new PlantCaretaker();
    std::vector<Plant*> greenhousePlants = nursery->getGreenhouse();
    
    for (int week=2; week<=4; week++) {
        std::cout << "\n--- Week " << week << " ---" << std::endl;
        
        //Kobe cares for plants
        std::cout << "\nKobe watering all plants..." << std::endl;
        Command* waterCmd = new WaterPlantsCommand(greenhousePlants);
        waterCmd->execute();
        delete waterCmd;
        
        // Advance time
        std::cout << "Week progressing..." << std::endl;
        Command* advanceCmd = new AdvanceTimeCommand(greenhousePlants, 1);
        advanceCmd->execute();
        delete advanceCmd;
        
        notifSystem->notify("Week " + std::to_string(week) + " care cycle completed");
    }
    
    nursery->displayInventory();
    
    //Week 5: Kobe's promotion
    std::cout<<"===WEEK 5: STAFF PROMOTION & ROLE EXPANSION===";
    
    std::cout << "!!!SPECIAL ANNOUNCEMENT!!!\n" << std::endl;
    std::cout << "Kobe has shown exceptional dedication to Grand Theft Nursery!" << std::endl;
    std::cout << "We see his hard work and the passion he has for the care of plants" << std::endl;
    std::cout << "We're promoting him with additional responsibilities!\n" << std::endl;
    
    notifSystem->notify("Kobe is being promoted to multi-role position!");
    
    //Promote Kobe and add Lanscaper role
    std::cout << "\nAdding Landscaper Role to Kobe:\n" << std::endl;
    Kobe = new LandscaperRole(Kobe);
    Kobe->displayRoles();
    
    std::cout << "\nKobe's Expanded Workday:\n" << std::endl;
    Kobe->executeWorkDay();
    
    //Week 6-8: Continue growinng plants and get them ready for sale
    std::cout<<"===WEEKS 6-8: PREPARING PLANTS FOR SALE==="<<std::endl;
    
    for (int week=5; week <= 8; week++) {
        std::cout << "\n--- Week " << week << " ---" << std::endl;
        nursery->careForGreenhouse();
        nursery->advanceTime(1);
        
        if (week == 8) {
            notifSystem->notify("Plants reaching maturity - prepare for move to sales floor!");
        }
    }

    // Continue caring to reach maturity (need age > 7)
    std::cout << "\n--- Extra Care Week (Week 9) ---" << std::endl;
    nursery->careForGreenhouse();
    nursery->advanceTime(1);

    
    nursery->displayInventory();
    //Moving plants manually. Need to add method for this in mediator
    greenhousePlants = nursery->getGreenhouse();
    std::vector<Plant*>& salesFloor = nursery->getSalesFloor();
    //Find and move mature or flowering plants
    auto it = greenhousePlants.begin();
    int movedCount = 0;
    while (it != greenhousePlants.end()) 
    {
        if (*it && ((*it)->getState() == "Mature" || (*it)->getState() == "Flowering")) 
        {
            std::cout << "Moving " << (*it)->getName() << " (" << (*it)->getState() 
                    << ") to sales floor..." << std::endl;
            salesFloor.push_back(*it);  // Add to sales floor
            it = greenhousePlants.erase(it);  // Remove from greenhouse
            movedCount++;
        } else {
            ++it;
        }
    }
    std::cout << "\nMoved plants to sales floor successfully\n" << std::endl;
    
    //Capitalism
    /* 
     asking for recommandations
     browsing plants 
     decoarate your plants
     bundle your order 
     either use order builder/ or the customer make purchase function to finalise the order 
    */
    //asking for recommandations and browsing plants 
    std::cout << "\nSales Floor Now OFFICIALLY Open!\n" << std::endl;
    std::cout <<"== Welcome beloved customer🎀 ==\n";
    Customer* JackJack = new Customer("JackJack", 1500.00);
    JackJack->askForRecommendation();
    JackJack->browseSalesFloor(salesFloor);

    //Decorate plants
    std::cout << "\n==🏗️ getting your oder ready==\n";
    std::vector<DecorativePotDecorator*> JackJacksPlants;
    it = salesFloor.begin(); //!is this allowed
    int count = 0;
    while (it != salesFloor.end()) 
    {   
        if((*it)->getType() == "Flower")
        { 
          JackJacksPlants.push_back(new DecorativePotDecorator((*it)));//making multiple decorator items
          JackJacksPlants[count]->display();
          ++count;
        }
        ++it;
    }

    //making the bundle order
    //using the decorator clone method to do this 
    std::cout << "\n==🔚 Finalising your order Jackjack==\n";
    std::vector<PlantItem*> JJPlants;
    PlantBundle* JackJacksOrder = new PlantBundle("JackJacks's order", 25.00);
    for (auto i = 0u; i < JackJacksPlants.size(); i++)
    {
       JJPlants.push_back(new PlantItem(JackJacksPlants[i]->clone()));
       JJPlants[i]->display();
    }

    std::cout << "\n==💳 Here are your totals==\n";
    for ( auto i = 0u; i < JJPlants.size(); i++)
    {
      JackJacksOrder->add(JJPlants[i]);
    }
    JackJacksOrder->display();
    JackJack->makePurchase(JackJacksOrder->getTotalValue());
    
    //clean-up
    //decorator 
    for (auto i = 0u; i < JackJacksPlants.size(); i++)
    {
      if(JackJacksPlants[i] != nullptr)
      {
         delete JackJacksPlants[i];
      }
    }
    JackJacksPlants.clear();
    delete JackJack;
    delete JackJacksOrder;
    std::cout << "\n== 🩵 Thank you hope to see you soon ==\n";



      
}



int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║             PLANT NURSERY MANAGEMENT SYSTEM                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    
    try {
        testNurserySimulation();
                
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
