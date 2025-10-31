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
#include "PlantComponent.h"
#include "PlantItem.h"
#include "PlantBundle.h"

void printSeparator(const std::string& title) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(60, '=') << "\n" << std::endl;
}

void testCompleteNurseryWorkflow() {    
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
    //decoarating the customers plant before final purchase
    Plant* flower = new Flower("Sunflower", 50);
    PlantDecorator* JackJackPlant = new DecorativePotDecorator(flower);
    //jackJackPlant->
    guy->makePurchase(100.00);




    delete guy;
    delete flower;
    delete JackJackPlant;
    

}



int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║             PLANT NURSERY MANAGEMENT SYSTEM                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;
    
    try {
        testCompleteNurseryWorkflow();
                
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
