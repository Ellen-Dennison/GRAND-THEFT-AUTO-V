#include <iostream>
#include <vector>
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

void printSeparator(const std::string& title) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(60, '=') << "\n" << std::endl;
}

void testVarietyOfPlants() {
    printSeparator("TEST 1: Creating Different Plant Varieties");
    
    std::vector<PlantFactory*> factories;
    
    // Different flowers at different prices
    factories.push_back(new FlowerFactory("Rose", 89.99));
    factories.push_back(new FlowerFactory("Tulip", 65.50));
    factories.push_back(new FlowerFactory("Sunflower", 45.00));
    factories.push_back(new FlowerFactory("Orchid", 125.00));
    
    // Different herbs
    factories.push_back(new HerbFactory("Basil", 65.00));
    factories.push_back(new HerbFactory("Rosemary", 72.50));
    factories.push_back(new HerbFactory("Thyme", 58.00));
    
    // Different succulents
    factories.push_back(new SucculentFactory("Aloe Vera", 55.00));
    factories.push_back(new SucculentFactory("Jade Plant", 48.50));
    factories.push_back(new SucculentFactory("Cactus", 45.50));
    
    // Different trees
    factories.push_back(new TreeFactory("Oak", 450.00));
    factories.push_back(new TreeFactory("Baobab", 350.00));
    factories.push_back(new TreeFactory("Pine", 280.00));
    
    std::cout << "\n--- Creating Plant Inventory ---\n" << std::endl;
    std::vector<Plant*> plants;
    for (PlantFactory* factory : factories) {
        Plant* plant = factory->createPlant();
        plants.push_back(plant);
        std::cout << "  " << plant->getName() << " (" << plant->getType() 
                  << ") - R" << plant->getPrice() << std::endl;
    }
    
    std::cout << "\n--- Detailed Plant Information ---\n" << std::endl;
    for (Plant* plant : plants) {
        plant->display();
        std::cout << std::endl;
    }
    
    // Cleanup
    for (Plant* p : plants) delete p;
    for (PlantFactory* f : factories) delete f;
}

void testPriceComparison() {
    printSeparator("TEST 2: Price Comparison & Inventory Value");
    
    std::vector<Plant*> inventory;
    
    // Create diverse inventory
    inventory.push_back((new FlowerFactory("Rose", 89.99))->createPlant());
    inventory.push_back((new FlowerFactory("Tulip", 65.50))->createPlant());
    inventory.push_back((new HerbFactory("Basil", 65.00))->createPlant());
    inventory.push_back((new SucculentFactory("Aloe Vera", 55.00))->createPlant());
    inventory.push_back((new TreeFactory("Oak", 450.00))->createPlant());
    
    double totalValue = 0.0;
    std::cout << "Current Inventory:\n" << std::endl;
    for (Plant* plant : inventory) {
        std::cout << "  " << plant->getName() << " (" << plant->getType() 
                  << ") - R" << plant->getPrice() << std::endl;
        totalValue += plant->getPrice();
    }
    
    std::cout << "\n  Total Inventory Value: R" << totalValue << std::endl;
    
    for (Plant* p : inventory) delete p;
}

void testPlantGrowthCycle() {
    printSeparator("TEST 3: Plant Growth Cycle");
    
    FlowerFactory roseFactory("Rose", 89.99);
    Plant* rose = roseFactory.createPlant();
    
    std::cout << "Growing a " << rose->getName() << " through its life cycle:\n" << std::endl;
    
    for (int week = 1; week <= 15; week++) {
        rose->grow();
        std::cout << "Week " << week << ": " << rose->getState() 
                  << " | Health: " << rose->getHealth() << "%" << std::endl;
    }
    
    delete rose;
}

void testWateringStrategies() {
    printSeparator("TEST 4: Watering Strategies & Automatic Neglect");
    
    std::vector<Plant*> plants;
    plants.push_back((new FlowerFactory("Rose", 89.99))->createPlant());
    plants.push_back((new HerbFactory("Basil", 65.00))->createPlant());
    plants.push_back((new SucculentFactory("Cactus", 45.50))->createPlant());
    plants.push_back((new TreeFactory("Oak", 450.00))->createPlant());
    
    std::cout << "Initial Plant Status:\n" << std::endl;
    for (Plant* plant : plants) {
        std::cout << plant->getName() << " (" << plant->getType() << "):" << std::endl;
        std::cout << "  Strategy: " << plant->getWateringInfo() << std::endl;
        std::cout << "  Health: " << plant->getHealth() << "%" << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "\n--- Week 1: Proper Care (Water All Plants) ---\n" << std::endl;
    for (Plant* plant : plants) {
        std::cout << "Caring for " << plant->getName() << ":" << std::endl;
        plant->water();
        plant->grow();
        std::cout << "  Health: " << plant->getHealth() << "%, Neglect: " 
                  << plant->getNeglectCounter() << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "\n--- Weeks 2-5: NEGLECTING Rose (No Watering) ---\n" << std::endl;
    Plant* neglectedPlant = plants[0];  // Rose
    
    for (int week = 2; week <= 5; week++) {
        std::cout << "=== Week " << week << " ===" << std::endl;
        
        // Only water other plants, NOT the rose
        for (size_t i = 1; i < plants.size(); i++) {
            plants[i]->water();
            plants[i]->grow();
        }
        
        // Rose grows WITHOUT watering (automatic neglect)
        std::cout << "Rose Status:" << std::endl;
        neglectedPlant->grow();
        std::cout << "  State: " << neglectedPlant->getState() 
                  << " | Health: " << neglectedPlant->getHealth() << "%"
                  << " | Neglect: " << neglectedPlant->getNeglectCounter() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "\n--- Weeks 6-10: Complete Abandonment of Basil ---\n" << std::endl;
    Plant* abandonedPlant = plants[1];  // Basil

    for (int week = 6; week <= 10; week++) {
        std::cout << "=== Week " << week << " ===" << std::endl;
        
        plants[0]->water();
        plants[2]->water();
        plants[3]->water();
        
        for (size_t i = 0; i < plants.size(); i++) {
            if (i != 1) plants[i]->grow();
        }
        
        //Basil heading to death
        std::cout << abandonedPlant->getName() << " Status:" << std::endl;
        abandonedPlant->grow();
        std::cout << "  State: " << abandonedPlant->getState() 
                << " | Health: " << abandonedPlant->getHealth() << "%"
                << " | Neglect: " << abandonedPlant->getNeglectCounter() << std::endl;
        std::cout << std::endl;
        
        if (abandonedPlant->getState() == "Dead") {
            std::cout<< abandonedPlant->getName() << " has died from neglect." << std::endl;
            break;
        }
    }
    
    /*std::cout << "\n--- Attempting Recovery: Watering Neglected Rose ---\n" << std::endl;
    for (int i = 1; i <= 3; i++) {
        std::cout << "Recovery Treatment " << i << ":" << std::endl;
        neglectedPlant->water();
        std::cout << "  State: " << neglectedPlant->getState() 
                  << " | Health: " << neglectedPlant->getHealth() << "%"
                  << " | Neglect: " << neglectedPlant->getNeglectCounter() << std::endl;
        std::cout << std::endl;
    }*/
    
    std::cout << "\n--- Final Status All Plants ---\n" << std::endl;
    for (Plant* plant : plants) {
        std::cout << plant->getName() << ": " 
                  << plant->getState() << " | Health: " << plant->getHealth() 
                  << "% | Neglect: " << plant->getNeglectCounter() << std::endl;
    }
    
    for (Plant* p : plants) delete p;
}

void testSaleReadiness() {
    printSeparator("TEST 5: Sale Readiness Check");
    
    std::vector<Plant*> nurseryStock;
    nurseryStock.push_back((new FlowerFactory("Tulip", 65.50))->createPlant());
    nurseryStock.push_back((new HerbFactory("Rosemary", 72.50))->createPlant());
    nurseryStock.push_back((new SucculentFactory("Jade Plant", 48.50))->createPlant());
    
    std::cout << "Checking which plants are ready for sale:\n" << std::endl;
    
    for (Plant* plant : nurseryStock) {
        std::cout << plant->getName() << " (Week 0):" << std::endl;
        std::cout << "  State: " << plant->getState() 
                  << " | Health: " << plant->getHealth() << "%"
                  << " | Ready: " << (plant->isReadyForSale() ? "Yes" : "No") << std::endl;
    }
    
    std::cout << "\n--- Growing plants for 8 weeks ---\n" << std::endl;
    
    for (int week = 0; week < 8; week++) {
        for (Plant* plant : nurseryStock) {
            plant->grow();
        }
    }
    
    std::cout << "After 8 weeks:\n" << std::endl;
    for (Plant* plant : nurseryStock) {
        std::cout << plant->getName() << ":" << std::endl;
        std::cout << "  State: " << plant->getState() 
                  << " | Health: " << plant->getHealth() << "%"
                  << " | Ready: " << (plant->isReadyForSale() ? "Yes ✓" : "No") << std::endl;
        std::cout << "  Sale Price: R" << plant->getPrice() << std::endl;
        std::cout << std::endl;
    }
    
    for (Plant* p : nurseryStock) delete p;
}

void testExpensiveVsCheapPlants() {
    printSeparator("TEST 6: Premium vs Budget Plants");
    
    std::cout << "PREMIUM PLANTS:\n" << std::endl;
    std::vector<Plant*> premiumPlants;
    premiumPlants.push_back((new FlowerFactory("Orchid", 125.00))->createPlant());
    premiumPlants.push_back((new TreeFactory("Oak", 450.00))->createPlant());
    
    for (Plant* plant : premiumPlants) {
        plant->display();
        std::cout << std::endl;
    }
    
    std::cout << "\nBUDGET-FRIENDLY PLANTS:\n" << std::endl;
    std::vector<Plant*> budgetPlants;
    budgetPlants.push_back((new SucculentFactory("Cactus", 45.50))->createPlant());
    budgetPlants.push_back((new HerbFactory("Thyme", 58.00))->createPlant());
    
    for (Plant* plant : budgetPlants) {
        plant->display();
        std::cout << std::endl;
    }
    
    for (Plant* p : premiumPlants) delete p;
    for (Plant* p : budgetPlants) delete p;
}

void testCompleteNurserySimulation() {
    printSeparator("TEST 7: Complete Nursery Simulation");
    
    std::cout << "Setting up nursery with mixed inventory...\n" << std::endl;
    
    std::vector<Plant*> nursery;
    nursery.push_back((new FlowerFactory("Rose", 89.99))->createPlant());
    nursery.push_back((new FlowerFactory("Sunflower", 45.00))->createPlant());
    nursery.push_back((new HerbFactory("Basil", 65.00))->createPlant());
    nursery.push_back((new SucculentFactory("Aloe Vera", 55.00))->createPlant());
    nursery.push_back((new TreeFactory("Pine", 280.00))->createPlant());
    
    std::cout << "Week-by-week care and growth:\n" << std::endl;
    
    for (int week = 1; week <= 10; week++) {
        std::cout << "=== Week " << week << " ===" << std::endl;
        
        for (Plant* plant : nursery) {
            // Provide care
            if (week % 1 == 0) plant->water();
            if (week % 2 == 0) plant->provideSunlight();
            if (week % 3 == 0) plant->fertilize();
            
            // Grow
            plant->grow();
        }
        
        // Show summary
        std::cout << "Plants Status:" << std::endl;
        for (Plant* plant : nursery) {
            std::cout << "  " << plant->getName() << ": " 
                      << plant->getState() << " (Health: " 
                      << plant->getHealth() << "%)" << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << "Final Nursery Inventory:\n" << std::endl;
    double totalValue = 0.0;
    int readyForSale = 0;
    
    for (Plant* plant : nursery) {
        plant->display();
        std::cout << std::endl;
        totalValue += plant->getPrice();
        if (plant->isReadyForSale()) readyForSale++;
    }
    
    std::cout << "Summary:" << std::endl;
    std::cout << "  Total Plants: " << nursery.size() << std::endl;
    std::cout << "  Ready for Sale: " << readyForSale << std::endl;
    std::cout << "  Total Inventory Value: R" << totalValue << std::endl;
    
    for (Plant* p : nursery) delete p;
}

void testDecorators() {
    printSeparator("TEST 8: Plant Decorators & Customization");
    
    std::cout << "=== CUSTOMER CUSTOMIZATION OPTIONS ===\n" << std::endl;
    
    //Create base plants
    Plant* rose = (new FlowerFactory("Rose", 89.99))->createPlant();
    Plant* basil = (new HerbFactory("Basil", 65.00))->createPlant();
    Plant* oak = (new TreeFactory("Oak", 450.00))->createPlant();
    
    std::cout << "--- Original Plants (No Customization) ---\n" << std::endl;
    std::cout << "1. "; rose->display();
    std::cout << "\n2. "; basil->display();
    std::cout << "\n3. "; oak->display();
    std::cout << std::endl;
    
    //Apply single decorations
    std::cout << "\n--- Single Decoration Options ---\n" << std::endl;
    
    std::cout << "OPTION A: Rose with Decorative Pot\n" << std::endl;
    Plant* decoratedRose = new DecorativePotDecorator(rose);
    decoratedRose->display();
    std::cout << std::endl;
    
    std::cout << "OPTION B: Basil with Gift Wrapping\n" << std::endl;
    Plant* giftBasil = new GiftWrappingDecorator(basil);
    giftBasil->display();
    std::cout << std::endl;
    
    //Stacking decorators
    std::cout << "\n--- Premium Package (Stacked Decorators) ---\n" << std::endl;
    std::cout << "Oak Tree - Decorative Pot + Gift Wrapping\n" << std::endl;
    Plant* decoratedOak = new DecorativePotDecorator(oak);
    Plant* premiumOak = new GiftWrappingDecorator(decoratedOak);
    premiumOak->display();
    std::cout << std::endl;
    
    //Price comparison
    std::cout << "\n--- Price Comparison Summary ---\n" << std::endl;
    Plant* sunflower = (new FlowerFactory("Sunflower", 45.00))->createPlant();
    Plant* potSunflower = new DecorativePotDecorator(
        (new FlowerFactory("Sunflower", 45.00))->createPlant()
    );
    Plant* giftSunflower = new GiftWrappingDecorator(
        (new FlowerFactory("Sunflower", 45.00))->createPlant()
    );
    Plant* fullPackageSunflower = new GiftWrappingDecorator(
        new DecorativePotDecorator(
            (new FlowerFactory("Sunflower", 45.00))->createPlant()
        )
    );
    
    std::cout << "Sunflower Options:" << std::endl;
    std::cout << "  Basic: R" << sunflower->getPrice() << std::endl;
    std::cout << "  + Decorative Pot: R" << potSunflower->getPrice() << std::endl;
    std::cout << "  + Gift Wrapping: R" << giftSunflower->getPrice() << std::endl;
    std::cout << "  + Both: R" << fullPackageSunflower->getPrice() << std::endl;
    std::cout << std::endl;
    
    //Test that decorated plants still function normally
    std::cout << "\n--- Decorated Plants Still Grow & Function ---\n" << std::endl;
    
    Plant* herb = (new HerbFactory("Rosemary", 72.50))->createPlant();
    Plant* decoratedHerb = new DecorativePotDecorator(herb);
    
    std::cout << "Before care:" << std::endl;
    std::cout << "  State: " << decoratedHerb->getState() 
              << " | Health: " << decoratedHerb->getHealth() << "%" << std::endl;
    
    decoratedHerb->water();
    decoratedHerb->grow();
    
    std::cout << "After watering & growing:" << std::endl;
    std::cout << "  State: " << decoratedHerb->getState() 
              << " | Health: " << decoratedHerb->getHealth() << "%" << std::endl;
    std::cout << "  Still functions normally with decoration!" << std::endl;
    std::cout << std::endl;
    
    // Customer scenarios
    std::cout << "\n--- Customer Purchase Scenarios ---\n" << std::endl;
    
    std::cout << "Scenario 1: Birthday Gift" << std::endl;
    Plant* birthdayGift = new GiftWrappingDecorator(
        new DecorativePotDecorator(
            (new FlowerFactory("Orchid", 125.00))->createPlant()
        )
    );
    birthdayGift->display();
    std::cout << std::endl;
    
    std::cout << "Scenario 2: Office Desk Plant (Basic)" << std::endl;
    Plant* deskPlant = (new SucculentFactory("Aloe Vera", 55.00))->createPlant();
    deskPlant->display();
    std::cout << std::endl;
    
    std::cout << "Scenario 3: Housewarming Present (Pot Only)" << std::endl;
    Plant* housewarmingGift = new DecorativePotDecorator(
        (new HerbFactory("Basil", 65.00))->createPlant()
    );
    housewarmingGift->display();
    std::cout << std::endl;
    
    // Cleanup
    delete decoratedRose;
    delete giftBasil;
    delete premiumOak;
    delete sunflower;
    delete potSunflower;
    delete giftSunflower;
    delete fullPackageSunflower;
    delete decoratedHerb;
    delete birthdayGift;
    delete deskPlant;
    delete housewarmingGift;
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
        
        printSeparator("ALL TESTS COMPLETED SUCCESSFULLY");
        
    } catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
