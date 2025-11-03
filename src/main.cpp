#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

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
#include "PlantItem.h"
#include "PlantBundle.h"
#include "OrderBuilder.h"
#include "Customer.h"
#include "SalesFloorWorker.h"
#include "WiltingState.h"

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
    StaffWorkFlow* Carie = new GreenhouseWorker("Carie", nursery);
    
    Kobe->displayRoles();
    std::cout << std::endl;
    Naledi->displayRoles();
    std::cout << std::endl;
    Trevor->displayRoles();
    std::cout << std::endl;
    Carie->displayRoles();
    std::cout << std::endl;
    
    //Setup observer system
    Subject* notifSystem = new Subject();
    ManagerObserver* manager = new ManagerObserver("Sarah");
    StaffObserver* kobeObs = new StaffObserver("Kobe", "GreenhouseWorker");
    StaffObserver* nalediObs = new StaffObserver("Naledi", "SalesAssociate");
    StaffObserver* carieObs = new StaffObserver("Carie", "SalesFloorWorker");
    
    notifSystem->attach(manager);
    notifSystem->attach(kobeObs);
    notifSystem->attach(nalediObs);
    notifSystem->attach(carieObs);
    
    std::cout << "\nNotification System Active!\n" << std::endl;

    //Register plant factories
    std::cout<<"Registering Plant Factories:\n\n";
    nursery->registerFactory("Flower", "Rose", new FlowerFactory("Rose", 89.99));
    nursery->registerFactory("Flower", "Tulip", new FlowerFactory("Tulip", 65.50));
    nursery->registerFactory("Flower", "Orchid", new FlowerFactory("Orchid", 125.00));
    nursery->registerFactory("Herb", "Basil", new HerbFactory("Basil", 65.00));
    nursery->registerFactory("Herb", "Rosemary", new HerbFactory("Rosemary", 72.50));
    nursery->registerFactory("Succulent", "Aloe Vera", new SucculentFactory("Aloe Vera", 55.00));
    nursery->registerFactory("Succulent", "Cactus", new SucculentFactory("Cactus", 45.50));
    nursery->registerFactory("Tree", "Oak", new TreeFactory("Oak", 450.00));

    nursery->displayRegisteredFactories();

    notifSystem->notify("Nursery is now open for business!");
    
    //Week 1: plantations:
    std::cout<<"===WEEK 1: PLANTING SEASON BEGINS==="<<std::endl;
    
    // Add diverse inventory
    std::cout << "\nReceiving New Seed Shipment....\n" << std::endl;

    std::cout << "Kobe's first day at work as a greenhouse worker. He plants new stock\n" << std::endl;

    int initialCount = nursery->getGreenhouseCount();

    nursery->addNewPlant("Flower", "Rose");      
    nursery->addNewPlant("Flower", "Rose");      
    nursery->addNewPlant("Flower", "Tulip");     
    nursery->addNewPlant("Flower", "Orchid");    
    nursery->addNewPlant("Herb", "Basil");       
    nursery->addNewPlant("Herb", "Rosemary");    
    nursery->addNewPlant("Succulent", "Aloe Vera"); 
    nursery->addNewPlant("Succulent", "Cactus"); 
    nursery->addNewPlant("Tree", "Oak"); 

    std::cout<<std::endl;
    Kobe->executeWorkDay();

    
    int plantsAdded = nursery->getGreenhouseCount() - initialCount;
    notifSystem->notify(std::to_string(plantsAdded) + " new plants added to greenhouse inventory");
    
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
    
    for (int week=2; week<=5; week++) {
        std::cout << "\n--- Week " << week << " ---" << std::endl;
        
        //Kobe cares for plants
        std::cout << "\nKobe watering all plants..." << std::endl;
        Command* waterCmd = new WaterPlantsCommand(greenhousePlants);
        waterCmd->execute();
        delete waterCmd;

        //Trevor cares for plants
        std::cout << "\nTrevor providing sunlight to all plants..." << std::endl;
        for (Plant* plant : greenhousePlants) {
            if (plant) {
                plant->provideSunlight();
            }
        }

        std::cout << "\nKobe fertilizing all plants..." << std::endl;
        for (Plant* plant : greenhousePlants) {
            if (plant) {
                plant->fertilize();
            }
        }
        
        // Advance time
        std::cout << "Week progressing..." << std::endl;
        Command* advanceCmd = new AdvanceTimeCommand(greenhousePlants, 1);
        advanceCmd->execute();
        delete advanceCmd;
        
        notifSystem->notify("Week " + std::to_string(week) + " care cycle completed");
    }
    
    nursery->displayInventory();
    
    //Week 5: Kobe's promotion
    std::cout<<"===WEEK 5: STAFF PROMOTION & ROLE EXPANSION==="<<std::endl;
    
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

    Command* advanceCmd = new AdvanceTimeCommand(greenhousePlants, 1);
    advanceCmd->execute();
    delete advanceCmd;
    
    //Week 6-8: Continue growinng plants and get them ready for sale
    std::cout<<"===WEEKS 6-8: PREPARING PLANTS FOR SALE==="<<std::endl;

    //add new plants so they can be neglected:
    nursery->addNewPlant("Herb", "Basil");       
    nursery->addNewPlant("Herb", "Rosemary");    
    nursery->addNewPlant("Succulent", "Aloe Vera"); 
    nursery->addNewPlant("Succulent", "Cactus"); 
    nursery->addNewPlant("Tree", "Oak"); 
    
    for (int week=6; week <= 8; week++) {
        std::cout << "\n--- Week " << week << " ---" << std::endl;
        nursery->careForGreenhouse();
        nursery->advanceTime(1);
        
        if (week == 8) {
            notifSystem->notify("Plants reaching maturity - prepare for move to sales floor!");
        }
    }

    nursery->harvestMaturePlants();
    nursery->displayInventory();

    std::cout<<std::endl;
    std::cout << "\nSales Floor Now OFFICIALLY Open and ready for customers to salvage!\n" << std::endl;

    //Week 9
    //Capitalism
    /* 
     asking for recommandations
     browsing plants 
     decoarate your plants
     bundle your order 
     either use order builder/ or the customer make purchase function to finalise the order 
    */

    // Week 9: Sales Day
    std::cout << "\n===!!!WEEK 9: GRAND OPENING - IT'S SALES DAY!!!=== " << std::endl;
    
    // Carie prepares the sales floor
    std::cout << "\nCarie preparing the sales floor for opening day..." << std::endl;
    Carie->executeWorkDay();
    
    // Naledi starts her shift
    std::cout << "\nNaledi starting her customer service shift..." << std::endl;
    Naledi->executeWorkDay();
    
    std::cout << "\n Doors are open! Customers are coming in ready to make purchases...\n" << std::endl;
    
    // === CUSTOMER 1: JackJack - Wants a Bundle ===
    std::cout << "\n--- Customer: JackJack arrives ---" << std::endl;
    std::cout << "== Welcome beloved customer ==\n" << std::endl;

    Customer* JackJack = new Customer("JackJack", 1500.00);

    Naledi->assistCustomer(JackJack);
    
    nursery->customerBrowsingInteraction(JackJack);

    JackJack->askForRecommendation();

    // JackJack selects flowers
    std::cout << "\nJackJack: 'I love flowers! I'll take all the flowers for a bouquet!'\n" << std::endl;
    std::cout << "Naledi: 'Wonderful! Let me create a beautiful flower bundle for you with 25% discount!'\n" << std::endl;

    // Ask about customization
    std::cout << "\nNaledi: 'Would you like a decorative pot for the bouquet?'" << std::endl;
    JackJack->requestCustomisation("decorative pot");
    
    std::cout << "\n==  Preparing your bundle order ==\n" << std::endl;
    
    //USE MEDIATOR to process bundle order! Mediator uses Builder internally
    PlantOrder* JackJacksOrder = nursery->processBundleOrder(
        "JackJack",                    // customer name
        "JackJack's Flower Bouquet",   // bundle name
        "Flower",                       // plant type
        25.0,                          // discount percentage
        true,                          // decorative pot on first item only
        false                          // no gift wrap
    );
    
    if (JackJacksOrder) {
        // Display order
        std::cout << "\n== 🔚 Finalising your order ==\n" << std::endl;
        JackJacksOrder->display();
        
        // Make purchase
        double totalCost = JackJacksOrder->getPlantComponent()->getTotalValue();
        std::cout << "\nProcessing payment...\n" << std::endl;
        
        if (JackJack->canAfford(totalCost)) {
            JackJack->makePurchase(totalCost);
            
            int flowerCount = JackJacksOrder->getPlantComponent()->getCount();
            notifSystem->notify("Bundle sale completed: " + std::to_string(flowerCount) + 
                            " flowers sold to JackJack!");
        } else {
            std::cout << " Insufficient funds. Purchase cancelled." << std::endl;
        }
        
        // Cleanup
        delete JackJacksOrder;
    } else {
        std::cout << " Unable to create bundle - insufficient inventory.\n" << std::endl;
    }
    
    delete JackJack;

    // === CUSTOMER 2: Tai Lung - Simple Order ===
    std::cout << "\n--- Customer 2: Tai Lung arrives ---" << std::endl;

    Customer* TaiLung = new Customer("Tai Lung", 300.00);

    std::cout << "Tai Lung: 'I need a single herb as a gift for my friend.'\n" << std::endl;
    TaiLung->askForRecommendation();

    nursery->customerBrowsingInteraction(TaiLung);

    std::cout << "\nNaledi: 'Perfect! Let me prepare that for you.'\n" << std::endl;
    std::cout << "Naledi: 'Would you like gift wrapping?'" << std::endl;
    std::cout << "Tai Lung: 'Yes please!'\n" << std::endl;
    TaiLung->requestCustomisation("gift wrapping");
    
    std::cout << "\n== 🏗️ Building your order ==\n" << std::endl;
    
    // USE MEDIATOR to process single order! Mediator uses Builder internally
    PlantOrder* TaiLungsOrder = nursery->processCustomerOrder(
        "Tai Lung",  // customer name
        "Herb",      // plant type
        false,       // no decorative pot
        true         // gift wrapping
    );
    
    if (TaiLungsOrder) {
        // Display order
        TaiLungsOrder->display();
        
        // Get total cost from the order
        double totalCost = TaiLungsOrder->getPlantComponent()->getTotalValue();
        
        std::cout << "\nTotal: R" << std::fixed << std::setprecision(2) << totalCost << std::endl;
        
        if (TaiLung->canAfford(totalCost)) {
            TaiLung->makePurchase(totalCost);
            notifSystem->notify("Gift-wrapped herb sold to Tai Lung!");
        } else {
            std::cout << " Insufficient funds. Purchase cancelled." << std::endl;
        }
        
        // Cleanup
        delete TaiLungsOrder;
    } else {
        std::cout << " No herbs available.\n" << std::endl;
    }
    
    delete TaiLung;

    std::cout << "\n==  Thank you, hope to see you soon! ==\n" << std::endl;

    // End of sales day - staff clock out
    std::cout << "\n--- End of Sales Day ---" << std::endl;
    std::cout << "\nStaff clocking out for the day...\n" << std::endl;
    
    // Cast to SalesAssociate to use endShift()
    SalesAssociate* nalediSales = dynamic_cast<SalesAssociate*>(Naledi);
    if (nalediSales) {
        nalediSales->endShift();
    }
    
    nursery->displayInventory();

    // === WEEK 10: THE SABOTAGE ===
    std::cout << "\n===WEEK 10: CORPORATE SABOTAGE===" << std::endl;
    std::cout << "\n CRIMINAL INVESTIGATION IN PROGRESS 🕵️" << std::endl;
    std::cout << "A rival nursery, 'Petals & Thorns', couldn't handle our success!" << std::endl;
    std::cout << "They sent a corporate spy who tampered with our fertilizer!" << std::endl;
    std::cout << "What we thought was premium plant food was actually HERBICIDE!" << std::endl;
    std::cout << "We've been POISONING our own plants for 3 days!\n" << std::endl;

    notifSystem->notify("CRIMINAL ALERT: Sabotage detected - plants poisoned!");

    std::cout << "Manager Sarah: 'WHO DID THIS?! Call the police!'" << std::endl;
    std::cout << "Kobe: 'No time for that! We need to save these plants!'" << std::endl;
    std::cout << "Naledi: 'I KNEW that delivery guy looked suspicious!'\n" << std::endl;

    greenhousePlants = nursery->getGreenhouse();
    std::cout << "\n Plants poisoned by contaminated fertilizer:\n" << std::endl;

    //Force plants into critical health and wilting state
    int affectedCount = 0;
    for (Plant* plant : greenhousePlants) {
        if (plant && plant->getState() != "Dead") {
            std::cout << "☠️ " << plant->getName() 
                    << " showing signs of chemical poisoning!" << std::endl;
            
            //Herbicide causes severe damage
            int currentHealth = plant->getHealth();
            int targetHealth = 25; // Critical but not dead
            int damage = currentHealth - targetHealth;
            
            if (damage > 0) {
                plant->adjustHealth(-damage);
                std::cout << "   Health dropped from " << currentHealth 
                        << "% to " << plant->getHealth() << "%" << std::endl;
            }
            
            // Force transition to wilting state
            if (plant->getState() != "Wilting") {
                plant->setState(new WiltingState());
                std::cout << "   State changed to: WILTING!" << std::endl;
            }
            
            affectedCount++;
        }
    }

    std::cout << "\n Total plants affected by sabotage: " << affectedCount << std::endl;

    std::cout << "\n*Emergency soil replacement and detox procedures...*" << std::endl;
    std::cout << "Carie: 'I'm replanting everything in fresh, uncontaminated soil!'" << std::endl;
    std::cout << "Trevor: 'We need to flush the roots with clean water!'" << std::endl;
    std::cout << "Kobe: 'Dispose of ALL the contaminated fertilizer immediately!'" << std::endl;

    std::cout << "\n Contaminated soil removed! Plants stabilized but barely alive..." << std::endl;
    std::cout << " Greenhouse secured and decontaminated" << std::endl;

    std::cout << "\n BREAKING NEWS:" << std::endl;
    std::cout << " 'Corporate Espionage at Grand Theft Nursery!'" << std::endl;
    std::cout << " 'Rival Nursery 'Petals & Thorns' Faces Criminal Charges!'" << std::endl;
    std::cout << " 'Local Nursery Fights to Save Poisoned Plants!'\n" << std::endl;

    // Check wilting status
    std::cout << "\n Damage Assessment:\n" << std::endl;
    nursery->checkForWiltingPlants();

    std::cout << "\nManager Sarah: 'This is a disaster... Can we save them?'" << std::endl;
    std::cout << "Kobe: 'We saved healthy plant states weeks ago for emergencies!'" << std::endl;
    std::cout << "Kobe: 'If we act fast, we can use those mementos to revive them!'" << std::endl;
    std::cout << "Manager Sarah: 'Do it! Whatever it takes!'\n" << std::endl;

    std::cout << " 24 hours pass as staff prepare emergency revival procedures..." << std::endl;
    Command* poisonTime = new AdvanceTimeCommand(greenhousePlants, 0);
    poisonTime->execute();
    delete poisonTime;

    std::cout << "\n Plants continue to deteriorate in wilting state..." << std::endl;
    nursery->checkForWiltingPlants();
    std::cout << "\n End of Week 10 Status:" << std::endl;
    nursery->displayInventory();
    
    // === WEEK 11: EMERGENCY REVIVAL OPERATIONS ===
    std::cout << "\n===WEEK 11: OPERATION PLANT REVIVAL===" << std::endl;
    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
    std::cout << "          🚨 EMERGENCY RECOVERY PROTOCOLS ACTIVATED 🚨" << std::endl;
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

    std::cout << "The team hasn't slept since discovering the sabotage..." << std::endl;
    std::cout << "But there's no time to rest, the plants are dying!" << std::endl;
    std::cout << "It's time to put the Memento Protocol to the ultimate test!\n" << std::endl;

    notifSystem->notify("INITIATING EMERGENCY REVIVAL PROTOCOL - ALL HANDS ON DECK!");

    greenhousePlants = nursery->getGreenhouse();

    // === PHASE 1: DAMAGE ASSESSMENT ===
    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              PHASE 1: DAMAGE ASSESSMENT                    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;

    std::vector<Plant*> criticalPlants;
    std::vector<Plant*> wiltingPlants;
    std::vector<Plant*> deadPlants;
    std::vector<Plant*> stablePlants;

    std::cout << "Kobe: 'Alright team, let's rescue mission this situation. Every plant counts!'\n" << std::endl;
    std::cout << " RESCUE MISSION REPORT:\n" << std::endl;
    std::cout << std::left << std::setw(20) << "Plant Name" 
            << std::setw(15) << "State" 
            << std::setw(12) << "Health" 
            << "Status" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;

    for (Plant* plant : greenhousePlants) {
        if (plant) {
            std::string state = plant->getState();
            int health = plant->getHealth();
            
            std::cout << std::left << std::setw(20) << plant->getName()
                    << std::setw(15) << state
                    << std::setw(12) << (std::to_string(health) + "%");
            
            if (state == "Dead") {
                std::cout << "💀 DECEASED" << std::endl;
                deadPlants.push_back(plant);
            } else if (state == "Wilting") {
                std::cout << "⚠️ CRITICAL - REVIVAL NEEDED NOW" << std::endl;
                wiltingPlants.push_back(plant);
            } else if (health < 50) {
                std::cout << "⚠️ POOR CONDITION" << std::endl;
                criticalPlants.push_back(plant);
            } else {
                std::cout << "✓ STABLE" << std::endl;
                stablePlants.push_back(plant);
            }
        }
    }

    std::cout << "\n RESCUE MISSION SUMMARY:" << std::endl;
    std::cout << "    Beyond Saving: " << deadPlants.size() << std::endl;
    std::cout << "    Needs Immediate Revival: " << wiltingPlants.size() << std::endl;
    std::cout << "    Needs Intensive Care: " << criticalPlants.size() << std::endl;
    std::cout << "    Stable (Minor Treatment): " << stablePlants.size() << std::endl;

    if (deadPlants.size() > 0) {
        std::cout << "\n Carie: 'We lost " << deadPlants.size() << " already... the herbicide worked too fast.'" << std::endl;
        std::cout << "Naledi: 'Let's make sure we don't lose any more!'\n" << std::endl;
    }

    if (wiltingPlants.empty() && criticalPlants.empty()) {
        std::cout << "\n All surviving plants are stable!" << std::endl;
        std::cout << "Manager Sarah: 'We got lucky. The sabotage could have been worse!'\n" << std::endl;
    } else {
        std::cout << "\nManager Sarah: 'We have " << wiltingPlants.size() 
                << " plants in critical wilting state!'" << std::endl;
        std::cout << "Kobe: 'Good thing we saved those healthy mementos back in Week 1!'" << std::endl;
        std::cout << "Trevor: 'If this works, it'll prove the Memento Protocol was worth implementing!'\n" << std::endl;
    }

    // === PHASE 2: EMERGENCY REVIVAL PROCEDURES ===
    if (!wiltingPlants.empty()) {
        std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║         PHASE 2: MEMENTO REVIVAL PROTOCOL                  ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;
        
        std::cout << "Kobe: 'Initiating revival sequence for " << wiltingPlants.size() << " wilting plants!'" << std::endl;
        std::cout << "Trevor: 'Accessing saved mementos from Week 1...'" << std::endl;
        std::cout << "Carie: 'Preparing revival substrate and support systems...'\n" << std::endl;
        
        int successfulRevivals = 0;
        int failedRevivals = 0;
        
        for (Plant* plant : wiltingPlants) {
            std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
            std::cout << " REVIVAL ATTEMPT: " << plant->getName() << std::endl;
            std::cout << "   Pre-Revival State: " << plant->getState() 
                    << " | Health: " << plant->getHealth() << "%" << std::endl;
            std::cout << "   Trevor: 'Loading memento from caretaker...'" << std::endl;
            std::cout << "   Kobe: 'Applying cellular regeneration protocol...'" << std::endl;
            
            // Use RevivePlantCommand with Memento
            Command* reviveCmd = new RevivePlantCommand(plant, nursery->getCaretaker(), plant->getName());
            reviveCmd->execute();
            delete reviveCmd;
            
            // Check revival success
            if (plant->getState() != "Wilting" && plant->getState() != "Dead") {
                std::cout << "    REVIVAL SUCCESSFUL!" << std::endl;
                std::cout << "   Post-Revival State: " << plant->getState() 
                        << " | Health: " << plant->getHealth() << "%" << std::endl;
                std::cout << "   Naledi: 'It's working! " << plant->getName() << " is coming back!'" << std::endl;
                successfulRevivals++;
            } else if (plant->getState() == "Dead") {
                std::cout << "    REVIVAL FAILED - Plant expired during procedure" << std::endl;
                std::cout << "   Carie: 'The damage was too severe...'" << std::endl;
                failedRevivals++;
            } else {
                std::cout << "    PARTIAL RESPONSE - Plant still wilting" << std::endl;
                std::cout << "   Kobe: 'We need to try again or increase treatment intensity'" << std::endl;
                failedRevivals++;
            }
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
        }
        
        std::cout << "\n REVIVAL PROTOCOL RESULTS:" << std::endl;
        std::cout << "    Successfully Revived: " << successfulRevivals << "/" << wiltingPlants.size() << std::endl;
        std::cout << "    Failed Revivals: " << failedRevivals << "/" << wiltingPlants.size() << std::endl;
        
        if (wiltingPlants.size() > 0) {
            double successRate = (successfulRevivals * 100.0) / wiltingPlants.size();
            std::cout << "   Success Rate: " << std::fixed << std::setprecision(1) 
                    << successRate << "%\n" << std::endl;
            
            if (successfulRevivals > 0) {
                notifSystem->notify("BREAKTHROUGH: Memento Protocol saved " + 
                                std::to_string(successfulRevivals) + " plants from certain death!");
            }
        }
    }

    // === PHASE 3: INTENSIVE CARE FOR ALL PLANTS ===
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         PHASE 3: INTENSIVE CARE TREATMENT                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;

    std::cout << "Manager Sarah: 'Now give EVERY survivor the VIP treatment!'" << std::endl;
    std::cout << "Kobe: 'Full recovery protocol, no shortcuts!'\n" << std::endl;

    // Refresh plant list after revivals
    greenhousePlants = nursery->getGreenhouse();

    std::cout << " STEP 1: THERAPEUTIC HYDRATION" << std::endl;
    std::cout << "Carie: 'Pure, filtered water - nothing contaminated!'\n" << std::endl;
    Command* cleanWater = new WaterPlantsCommand(greenhousePlants);
    cleanWater->execute();
    delete cleanWater;
    std::cout << " All plants hydrated with clean water!\n" << std::endl;

    std::cout << " STEP 2: OPTIMIZED LIGHT THERAPY" << std::endl;
    std::cout << "Trevor: 'Adjusting spectrum and intensity for each species...'\n" << std::endl;
    for (Plant* plant : greenhousePlants) {
        if (plant && plant->getState() != "Dead") {
            std::cout<< plant->getName() << ": ";
            plant->provideSunlight();
        }
    }
    std::cout << " Light therapy complete!\n" << std::endl;

    std::cout << "STEP 3: ORGANIC NUTRIENT BOOST" << std::endl;
    std::cout << "Kobe: 'Triple-checked, this is CERTIFIED organic fertilizer!'" << std::endl;
    std::cout << "Naledi: 'No more risks, I'm inspecting every bag personally!'\n" << std::endl;
    for (Plant* plant : greenhousePlants) {
        if (plant && plant->getState() != "Dead") {
            std::cout<< plant->getName() << ": ";
            plant->fertilize();
        }
    }
    std::cout << " Nutrient boost administered!\n" << std::endl;

    // === PHASE 4: RECOVERY MONITORING ===
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         PHASE 4: RECOVERY MONITORING                       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;

    std::cout << "Manager Sarah: 'Everyone, take shifts. Monitor them around the clock.'" << std::endl;
    std::cout << "Kobe: 'I'll take first watch.'" << std::endl;
    std::cout << "⏰ One week of intensive 24/7 monitoring begins...\n" << std::endl;

    // Advance time
    Command* monitoringWeek = new AdvanceTimeCommand(greenhousePlants, 1);
    monitoringWeek->execute();
    delete monitoringWeek;


    // === PHASE 5: FINAL RECOVERY ASSESSMENT ===
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         PHASE 5: RECOVERY ASSESSMENT                       ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝\n" << std::endl;

    std::cout << "The team gathers for the moment of truth...\n" << std::endl;

    greenhousePlants = nursery->getGreenhouse();

    int healthyCount = 0;
    int improvingCount = 0;
    int stillCriticalCount = 0;
    int newDeaths = 0;

    std::cout << " WEEK 11 RECOVERY STATUS:\n" << std::endl;
    std::cout << std::left << std::setw(20) << "Plant Name" 
            << std::setw(15) << "State" 
            << std::setw(12) << "Health" 
            << "Assessment" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;

    for (Plant* plant : greenhousePlants) {
        if (plant) {
            std::string state = plant->getState();
            int health = plant->getHealth();
            
            std::cout << std::left << std::setw(20) << plant->getName()
                    << std::setw(15) << state
                    << std::setw(12) << (std::to_string(health) + "%");
            
            if (state == "Dead") {
                std::cout << " LOST" << std::endl;
                newDeaths++;
            } else if (health >= 70) {
                std::cout << " THRIVING" << std::endl;
                healthyCount++;
            } else if (health >= 50) {
                std::cout << " RECOVERING" << std::endl;
                improvingCount++;
            } else {
                std::cout << " FRAGILE" << std::endl;
                stillCriticalCount++;
            }
        }
    }

    std::cout << "\n FINAL RECOVERY STATISTICS:" << std::endl;
    std::cout << "    Thriving: " << healthyCount << std::endl;
    std::cout << "    Recovering: " << improvingCount << std::endl;
    std::cout << "    Still Fragile: " << stillCriticalCount << std::endl;
    std::cout << "    Total Losses: " << (deadPlants.size() + newDeaths) << std::endl;

    int totalSurvivors = healthyCount + improvingCount + stillCriticalCount;
    int totalPlants = totalSurvivors + deadPlants.size() + newDeaths;
    double survivalRate = (totalSurvivors * 100.0) / totalPlants;

    std::cout << "\n   🎯 Overall Survival Rate: " << std::fixed << std::setprecision(1) 
            << survivalRate << "%" << std::endl;

    // Check for remaining issues
    nursery->checkForWiltingPlants();

    //TL;DR
    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;

    if (survivalRate >= 80) {
        std::cout << "\n🎉 MIRACULOUS RECOVERY! 🎉" << std::endl;
        std::cout << "Manager Sarah: 'You all saved this nursery! The Memento Protocol WORKS!'" << std::endl;
        std::cout << "Kobe: 'Saving those healthy states was the best decision we ever made!'" << std::endl;
        std::cout << "Trevor: 'We turned a disaster into a triumph!'" << std::endl;
        std::cout << "Carie: 'Petals & Thorns tried to destroy us, but we're STRONGER now!'" << std::endl;
        std::cout << "Naledi: 'Grand Theft Nursery doesn't back down!'" << std::endl;
        notifSystem->notify("VICTORY: " + std::to_string((int)survivalRate) + 
                        "% survival rate! Memento Protocol proves its worth!");
    } else if (survivalRate >= 60) {
        std::cout << "\n✅ HARD-FOUGHT VICTORY!" << std::endl;
        std::cout << "Manager Sarah: 'We took casualties, but we saved the heart of our nursery!'" << std::endl;
        std::cout << "Kobe: 'Every plant we saved is a win against those saboteurs!'" << std::endl;
        std::cout << "Team: 'We'll rebuild stronger than ever!'" << std::endl;
        notifSystem->notify("Crisis survived! " + std::to_string((int)survivalRate) + "% survival rate achieved through teamwork!");
    } else {
        std::cout << "\n💪 WE SURVIVED!" << std::endl;
        std::cout << "Manager Sarah: 'The damage was catastrophic, but we didn't give up!'" << std::endl;
        std::cout << "Kobe: 'We lost many, but those that survived will be our foundation!'" << std::endl;
        std::cout << "Team: 'We'll honor the lost by making this nursery better than ever!'" << std::endl;
        notifSystem->notify("Against all odds, we survived the sabotage!");
    }

    std::cout << "\n  MEDIA RESPONSE:" << std::endl;
    std::cout << " 'Heroic Nursery Staff Defies Corporate Sabotage!'" << std::endl;
    std::cout << " 'Innovative Plant Revival Technique Saves Grand Theft Nursery!'" << std::endl;
    std::cout << " 'Justice Served: Petals & Thorns Owner Denied Bail!'" << std::endl;
    std::cout << " 'Community Donations Pour In to Support Local Nursery!'" << std::endl;
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

    // Harvest any recovered mature plants
    std::cout << " Checking for plants ready to return to sales floor...\n" << std::endl;
    nursery->harvestMaturePlants();

    // Display inventory
    nursery->displayInventory();

    std::cout << "\nKobe: 'Crisis management: Complete. Now let's get back to business!'" << std::endl;
    
    //Week 12
    std::cout << "\n===WEEK 12: EXPANSION & QUARTERLY PERFORMANCE REVIEW===" << std::endl;

    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
    std::cout << "            SPECIAL ANNOUNCEMENT - PROMOTIONS! " << std::endl;
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

    std::cout << "Grand Theft Nursery has THRIVED for survival" << std::endl;
    std::cout << "After weathering the sabotage crisis, we're stronger than ever!" << std::endl;
    std::cout << "Time to recognize our heroes and expand operations!\n" << std::endl;

    //Promotion for heroic efforts during sabotage crisis
    std::cout << "Manager Sarah: 'I want to recognize some extraordinary efforts...'\n" << std::endl;

    std::cout << "!!!CARIE'S PROMOTION!!!" << std::endl;
    std::cout << "Carie showed unwavering dedication during the sabotage crisis!" << std::endl;
    std::cout << "She worked tirelessly to decontaminate soil and save every plant!" << std::endl;
    std::cout << "Her quick thinking and hard work saved countless lives!" << std::endl;
    std::cout << "She's being promoted with full sales responsibilities!\n" << std::endl;

    notifSystem->notify("Carie promoted to Sales Floor Worker + Sales for heroic crisis response!");

    Carie = new SalesRole(Carie);
    std::cout << "Carie's Expanded Responsibilities:" << std::endl;
    Carie->displayRoles();
    std::cout << "\nCarie: 'Thank you! I won't let you down!'" << std::endl;

    //register new factories for incoming stock:
    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
    std::cout << "                 NURSERY EXPANSION BEGINS"                << std::endl;
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

    std::cout << "The community's support after the sabotage has been overwhelming!" << std::endl;
    std::cout << "Donations and new customers are flooding in!" << std::endl;
    std::cout << "Time to expand our plant varieties!\n" << std::endl;

    std::cout << "Manager Sarah registers new plant factories to expand stock variety..." << std::endl;
    std::cout << "All new suppliers have been THOROUGHLY vetted after the incident!\n" << std::endl;

    nursery->registerFactory("Flower", "Lilly", new FlowerFactory("Lilly", 129.99));
    nursery->registerFactory("Tree", "Bonsai", new TreeFactory("Bonsai", 580.00));
    nursery->registerFactory("Succulent", "Cussonia", new SucculentFactory("Cussonia", 129.99));
    nursery->registerFactory("Tree", "Willow", new TreeFactory("Willow", 599.99));
    nursery->registerFactory("Herb", "Oregano", new HerbFactory("Oregano", 79.99));

    nursery->displayRegisteredFactories();

    // Add some new stock for expansion
    std::cout << "\n📦 Receiving Verified, Certified New Stock:\n" << std::endl;
    std::cout << "Kobe: 'Every shipment inspected personally. No more surprises!'\n" << std::endl;
    std::cout<<"Kobe plants the new stock..."<<std::endl;

    nursery->addMultiplePlants("Flower", "Lilly", 15);
    nursery->addMultiplePlants("Flower", "Rose", 15);
    nursery->addMultiplePlants("Flower", "Orchid", 15);
    nursery->addMultiplePlants("Flower", "Tulip", 15);
    nursery->addMultiplePlants("Tree", "Bonsai", 15);
    nursery->addMultiplePlants("Tree", "Willow", 15);
    nursery->addMultiplePlants("Tree", "Oak", 15);
    nursery->addMultiplePlants("Succulent", "Cussonia", 15);
    nursery->addMultiplePlants("Succulent", "Aloe Vera", 15);
    nursery->addMultiplePlants("Succulent", "Cactus", 15);
    nursery->addMultiplePlants("Herb", "Basil", 15);
    nursery->addMultiplePlants("Herb", "Rosemary", 15);
    nursery->addMultiplePlants("Herb", "Oregano", 15);

    std::cout << "\nAll new plants safely planted and catalogued!" << std::endl;

    //!Could add security role since incident

    // Save healthy states for new plants
    std::cout << "Kobe: 'Saving healthy states for all new plants - lesson learned!'" << std::endl;
    nursery->saveHealthyStates();
    std::cout << "All plant states backed up!\n" << std::endl;

    // Final care cycle
    std::cout << "\n  Final Weekly Care Cycle:" << std::endl;
    nursery->careForGreenhouse();
    nursery->advanceTime(1);

    // === QUARTERLY PERFORMANCE SUMMARY ===
    std::cout << "\n╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout <<   "║         QUARTERLY PERFORMANCE SUMMARY (12 WEEKS)           ║" << std::endl;
    std::cout <<   "╚════════════════════════════════════════════════════════════╝" << std::endl;

    std::cout << "\n  INVENTORY STATISTICS:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "Current Greenhouse Plants: " << nursery->getGreenhouseCount() << std::endl;
    std::cout << "Current Sales Floor Plants: " << nursery->getSalesFloorCount() << std::endl;

    // Count by type
    std::cout << "\n  PLANT BREAKDOWN:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;

    std::vector<std::string> plantTypes = {"Flower", "Herb", "Succulent", "Tree"};
    for (const auto& type : plantTypes) {
        int greenhouse = nursery->getPlantCountByType(type, true);
        int salesFloor = nursery->getPlantCountByType(type, false);
        std::cout << type << "s - Greenhouse: " << greenhouse 
                << ", Sales Floor: " << salesFloor 
                << ", Total: " << (greenhouse + salesFloor) << std::endl;
    }

    // Display sales statistics
    nursery->displaySalesStatistics();

    std::cout << "\n👥 STAFF ROSTER & ROLES:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "\n";
    Kobe->displayRoles();
    std::cout << "\n";
    Naledi->displayRoles();
    std::cout << "\n";
    Trevor->displayRoles();
    std::cout << "\n";
    Carie->displayRoles();

    std::cout << "\n KEY ACHIEVEMENTS:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "✅ Successfully grew plants from seeds to maturity" << std::endl;
    std::cout << "✅ Opened sales floor and served customers" << std::endl;
    std::cout << "✅ Completed bundle and individual plant sales" << std::endl;
    std::cout << "✅ SURVIVED CORPORATE SABOTAGE ATTACK" << std::endl;
    std::cout << "✅ Successfully revived poisoned plants using Memento Protocol" << std::endl;
    std::cout << "✅ Brought saboteurs to justice, criminal charges filed" << std::endl;
    std::cout << "✅ Promoted exceptional staff members" << std::endl;
    std::cout << "✅ Expanded inventory" << std::endl;
    std::cout << "✅ Gained community support and loyalty" << std::endl;

    std::cout << "\nSPECIAL RECOGNITION:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "Innovation Award: Memento Protocol saved the nursery" << std::endl;
    std::cout << "Resilience Award: Turned crisis into opportunity" << std::endl;
    std::cout << "Team Spirit Award: United against adversity" << std::endl;

    std::cout << "\nFINAL NOTIFICATIONS:" << std::endl;
    notifSystem->notify("Quarter 1 complete - Grand Theft Nursery THRIVES despite sabotage!");
    notifSystem->notify("Quarter goals: Expansion, enhanced security, and record sales!");
    notifSystem->notify("Petals & Thorns permanently shut down by authorities!");

    // Final inventory display
    std::cout << "\nFINAL INVENTORY STATUS:" << std::endl;
    nursery->displayInventory();

    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
    std::cout << "  FROM SABOTAGE TO TRIUMPH - A QUARTER OF RESILIENCE  " << std::endl;
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

    std::cout << "Manager Sarah: 'They tried to destroy us, but we came back stronger!'" << std::endl;
    std::cout << "Kobe: 'Our plants survived poison that's what I call the ultimate quality test!'" << std::endl;
    std::cout << "Trevor: 'Customers know they can trust Grand Theft Nursery!'" << std::endl;
    std::cout << "Carie: 'We're a community!'" << std::endl;
    std::cout << "Naledi: 'Quarter 2 is going to be LEGENDARY!'\n" << std::endl;

    std::cout << "╔════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║              GREEN THUMBS, GREENER PROFITS!                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════╝" << std::endl;

    // Cleanup
    delete Kobe;
    delete Naledi;
    delete Trevor;
    delete Carie;
    delete notifSystem;
    delete nursery;

    std::cout << "\nSimulation complete. Thank you for visiting Grand Theft Nursery!" << std::endl;
    
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
