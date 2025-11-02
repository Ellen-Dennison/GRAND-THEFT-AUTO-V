#include "NurseryMediator.h"
#include "FlowerFactory.h"
#include "SucculentFactory.h"
#include "TreeFactory.h"
#include "HerbFactory.h"
#include "PlantMemento.h"
#include "OrderBuilder.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>

NurseryMediator::NurseryMediator() {
    careTaker = new PlantCaretaker();

    //Iinitalise tracking vars
    totalRevenue = 0.0;
    totalCustomers = 0;
    bundleOrderCount = 0;
    individualOrderCount = 0;
    plantsWithPots = 0;
    plantsWithGiftWrap = 0;

    std::cout << "🏗️ NurseryMediator initialized.\n";
}

NurseryMediator::~NurseryMediator() {
    for (auto* plant : greenhouse)
        delete plant;
    for (auto* plant : salesFloor)
        delete plant;

    delete careTaker;

    //Edits
    for (auto& typeEntry : factories){
        for(auto& plantEntry : typeEntry.second){
            delete plantEntry.second;

        }
    }

    factories.clear();
    greenhouse.clear();
    salesFloor.clear();

    std::cout << "🏁 NurseryMediator destroyed.\n";
}

//if we were to grow the Nursery and add more Plant types. This adds factories according to our custom instead of already set ones
//1. Register Factory
void NurseryMediator::registerFactory(const std::string& plantType, const std::string& plantName, PlantFactory* factory) {
    if (!factory) {
        std::cout << "Cannot register a null factory." <<std::endl;
        return;
    }
    
    //Check if this variety is already registered
    if (factories[plantType].find(plantName) != factories[plantType].end()) {
        std::cout<<plantName << " already registered in " << plantType << " collection. Replacing..." <<std::endl;
        delete factories[plantType][plantName];
    }
    
    factories[plantType][plantName] = factory;
    std::cout << "Registered a " << plantName << " in " << plantType << " factory."<<std::endl;
    std::cout<<std::endl;
}

//Managing plants. adding them
void NurseryMediator::addNewPlant(const std::string& plantType, const std::string& plantName) {
    //Check if plant type exists
    auto typeIt = factories.find(plantType);
    if (typeIt == factories.end()) {
        std::cout << "No " << plantType << " factories registered."<<std::endl;
        return;
    }
    
    //Check if specific concrete exists for this plant type
    auto nameIt = typeIt->second.find(plantName);
    if (nameIt == typeIt->second.end()) {
        std::cout << "No factory registered for " << plantName << " " << plantType << "." <<std::endl;
        return;
    }

    Plant* newPlant = nameIt->second->createPlant();
    
    if (!newPlant) {
        std::cout << "Failed to create plant." <<std::endl;
        return;
    }

    greenhouse.push_back(newPlant);
    std::cout<< newPlant->getName() << " (" << newPlant->getType() 
         << ") added to greenhouse - R" << newPlant->getPrice() <<std::endl;
}

void NurseryMediator::addMultiplePlants(const std::string& plantType, const std::string& plantName, int qty) {
    if (qty <= 0) {
        std::cout<< "Quantity must be greater than 0!" <<std::endl;
        return;
    }
    
    std::cout<< "\nCreating " << qty << " " << plantName << " " << plantType<<"(s)..."<<std::endl;
    
    for (int i = 0; i < qty; ++i) {
        addNewPlant(plantType, plantName);
    }
}

bool NurseryMediator::removePlantFromGreenhouse(Plant* plant) {
    auto it = find(greenhouse.begin(), greenhouse.end(), plant);
    if (it != greenhouse.end()) {
        greenhouse.erase(it);
        return true;
    }
    return false;
}

bool NurseryMediator::removePlantFromSalesFloor(Plant* plant) {
    auto it = find(salesFloor.begin(), salesFloor.end(), plant);
    if (it != salesFloor.end()) {
        salesFloor.erase(it);
        return true;
    }
    return false;
}

// 💧 Care for plants
void NurseryMediator::careForGreenhouse() {
    std::cout << "\n💧 Caring for greenhouse plants...\n";
    for (auto* plant : greenhouse) {
        plant->water();
        plant->provideSunlight();
        plant->fertilize();
        std::cout << "✅ " << plant->getName() << " cared for.\n";
    }
}

// ⏳ Advance time
void NurseryMediator::advanceTime(int weeks) {
    std::cout << "\n⏳ Advancing time by " << weeks << " weeks...\n";
    for (auto* plant : greenhouse)
        for (int i = 0; i < weeks; ++i)
            plant->grow();

    harvestMaturePlants();
}

// 🌾 Move mature plants to sales floor
void NurseryMediator::harvestMaturePlants() {
    if (greenhouse.empty()) {
        std::cout << "\n🌾 Greenhouse is empty - nothing to harvest.\n";
        return;
    }
    
    std::cout << "\n🌾 Checking for plants ready to harvest...\n";
    
    auto it = greenhouse.begin();
    int harvestedCount = 0;
    
    while (it != greenhouse.end()) {
        Plant* plant = *it;
        if (plant->isReadyForSale()) {
            std::cout << "🪴 " << plant->getName() << " (" << plant->getState() 
                 << ", Health: " << plant->getHealth() << "%) moved to sales floor.\n";
            salesFloor.push_back(plant);
            it = greenhouse.erase(it);
            ++harvestedCount;
        } else {
            ++it;
        }
    }
    
    if (harvestedCount == 0) {
        std::cout << "⏳ No plants ready for harvest yet.\n";
    } else {
        std::cout << "✅ Harvested " << harvestedCount << " plant" 
             << (harvestedCount > 1 ? "s" : "") << ".\n";
    }

    displaySalesFloorInventory();
}

// 💾 Save healthy states (Memento)
void NurseryMediator::saveHealthyStates() {
    if (greenhouse.empty()) {
        std::cout << "💾 No plants in greenhouse to save.\n";
        return;
    }
    
    std::cout << "\n💾 Saving healthy plant states...\n";
    int savedCount = 0;
    
    for (auto* plant : greenhouse) {
        if (plant->getHealth() > 70) {
            careTaker->saveMemento(plant->getName(), plant->createMemento());
            std::cout << "📸 Saved state for " << plant->getName() 
                 << " (Health: " << plant->getHealth() << "%)\n";
            ++savedCount;
        }
    }
    
    if (savedCount == 0) {
        std::cout << "⚠️ No plants healthy enough (>70%) to save.\n";
    } else {
        std::cout << "✅ Saved " << savedCount << " plant state" 
             << (savedCount > 1 ? "s" : "") << ".\n";
    }
}

// 🧪 Check for wilting plants
void NurseryMediator::checkForWiltingPlants() {
    if (greenhouse.empty()) {
        std::cout << "\n🧪 Greenhouse is empty.\n";
        return;
    }
    
    std::cout << "\n🧪 Checking for wilting plants...\n";
    int wiltingCount = 0;
    
    for (auto* plant : greenhouse) {
        if (plant->getHealth() < 40) {
            std::cout << "⚠️ " << plant->getName() << " is in poor condition! Health = "
                 << plant->getHealth() << "%, State: " << plant->getState() << std::endl;
            ++wiltingCount;
        }
    }
    
    if (wiltingCount == 0) {
        std::cout << "✅ All plants are healthy!\n";
    } else {
        std::cout << "⚠️ Found " << wiltingCount << " plant" 
             << (wiltingCount > 1 ? "s" : "") << " in poor condition.\n";
    }
}

// 🛍️ Process customer orders
PlantOrder* NurseryMediator::processCustomerOrder(const std::string cusName, std::string plantType, bool wantsPot, bool wantsWrapping) {
    std::cout << "\n🛍️ Processing order for " << cusName << ": " << plantType << std::endl;

    for (auto it = salesFloor.begin(); it != salesFloor.end(); ++it) {
        Plant* plant = *it;
        if (plant->getType() == plantType) {
            //Use OrderBuilder to create the order
            OrderBuilder* builder = new OrderBuilder();
            PlantOrder* order = builder->setCustomer(cusName)
                                       ->setPlant(plant, wantsPot, wantsWrapping)
                                       ->build();
            
            delete builder;

            if (order) {
                //Track sales
                totalCustomers++;
                individualOrderCount++;
                if (wantsPot) plantsWithPots++;
                if (wantsWrapping) plantsWithGiftWrap++;
                totalRevenue += order->getPlantComponent()->getTotalValue();
                
                std::cout << "✅ Order created for " << cusName << " (" << plant->getName() << ")\n";
                salesFloor.erase(it);
            }
            
            return order;
        }
    }

    std::cout << "❌ No " << plantType << " plants available.\n";
    return NULL;
}

//Process Bundle order:
PlantOrder* NurseryMediator::processBundleOrder(const std::string& cusName, const std::string& bundleName, const std::string& plantType, double discount, bool decorativePotOnFirst, bool giftWrapAll) {
    std::cout << "\n🛍️ Processing bundle order for " << cusName << std::endl;
    
    std::vector<Plant*> selectedPlants;
    for (Plant* plant : salesFloor) {
        if (plant && plant->getType() == plantType) {
            selectedPlants.push_back(plant);
        }
    }
    
    if (selectedPlants.empty()) {
        std::cout << "❌ No " << plantType << " plants available for bundle.\n";
        return NULL;
    }
    
    OrderBuilder* builder = new OrderBuilder();
    builder->setCustomer(cusName)->startBundle(bundleName, discount);
    
    for (size_t i = 0; i < selectedPlants.size(); i++) {
        bool addPot = (decorativePotOnFirst && i == 0);
        bool addWrap = giftWrapAll;
        
        builder->addPlantToBundle(selectedPlants[i], addPot, addWrap);
        
        //Track decor
        if (addPot) plantsWithPots++;
        if (addWrap) plantsWithGiftWrap++;
    }
    
    PlantOrder* order = builder->finishBundle()->build();
    delete builder;
    
    if (order) {
        //Track sales
        totalCustomers++;
        bundleOrderCount++;
        totalRevenue += order->getPlantComponent()->getTotalValue();
        
        //remove bought plants
        for (Plant* plant : selectedPlants) {
            removePlantFromSalesFloor(plant);
        }
        
        std::cout << "✅ Bundle order created for " << cusName 
                  << " with " << selectedPlants.size() << " " << plantType << "(s)\n";
    }
    
    return order;
}

// 👀 Customer browsing
void NurseryMediator::customerBrowsingInteraction(Customer* customer) {
    //add null check
    if (!customer) {
        std::cout << "Invalid customer.\n";
        return;
    }

    std::cout << "\n👀 " << customer->getName() << " is browsing the sales floor...\n";
    customer->browseSalesFloor(salesFloor);
}

//Inventory display
void NurseryMediator::displayInventory() const {
    std::cout << "\n═══════════════════════════════════════════════════\n";
    std::cout << "        NURSERY INVENTORY SUMMARY\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    std::cout << "Greenhouse Plants: " << greenhouse.size() << std::endl;
    std::cout << "Sales Floor Plants: " << salesFloor.size() << std::endl;
    std::cout << "Registered Factories: " << factories.size() << " types\n";
    std::cout << "═══════════════════════════════════════════════════\n";

    displayGreenhouseInventory();
    displaySalesFloorInventory();
}
void NurseryMediator::displayGreenhouseInventory() const {
    if (greenhouse.empty()) {
        std::cout << "\nGreenhouse: Empty\n";
        return;
    }
    
    std::cout << "\nGREENHOUSE PLANTS:\n";
    std::cout << "─────────────────────────────────────────────────────────────────────\n";
    // Group plants by name
    std::map<std::string, std::vector<Plant*>> plantGroups;
    for (Plant* plant : greenhouse) {
        if (plant) {
            plantGroups[plant->getName()].push_back(plant);
        }
    }
    
    // Display grouped plants with quantities
    for (const auto& group : plantGroups) {
        const std::string& plantName = group.first;
        const std::vector<Plant*>& plants = group.second;
        int quantity = plants.size();
        
        //Use the first plant for details
        Plant* plant = plants[0];
        
        std::cout << "  • " 
                  << std::left << std::setw(16) << plantName
                  << std::setw(14) << ("(" + plant->getType() + ")")
                  << std::setw(18) << ("State: " + plant->getState())
                  << std::setw(15) << ("Health: " + std::to_string(plant->getHealth()) + "%")
                  << std::setw(14) << ("Age: " + std::to_string(plant->getAge()) + " weeks")
                  << "Qty: " << quantity
                  << std::endl;
    }
}

void NurseryMediator::displaySalesFloorInventory() const {
    if (salesFloor.empty()) {
        std::cout << "\nSales Floor: Empty\n";
        return;
    }
    
    std::cout << "\nSALES FLOOR PLANTS:\n";
    std::cout << "─────────────────────────────────────────────────────────────────────\n";
    // Group plants by name
    std::map<std::string, std::vector<Plant*>> plantGroups;
    for (Plant* plant : salesFloor) {
        if (plant) {
            plantGroups[plant->getName()].push_back(plant);
        }
    }
    
    // Display grouped plants with quantities
    for (const auto& group : plantGroups) {
        const std::string& plantName = group.first;
        const std::vector<Plant*>& plants = group.second;
        int quantity = plants.size();
        
        // Use the first plant for details
        Plant* plant = plants[0];
        
        std::ostringstream priceStream;
        priceStream << std::fixed << std::setprecision(2) << plant->getPrice();
        
        std::cout << "  • " 
                  << std::left << std::setw(18) << plantName
                  << std::setw(14) << ("(" + plant->getType() + ")")
                  << std::setw(18) << ("State: " + plant->getState())
                  << std::setw(16) << ("Price: R" + priceStream.str())
                  << "Qty: " << quantity
                  << std::endl;
    }
}

void NurseryMediator::displayRegisteredFactories() const {
    if (factories.empty()) {
        std::cout << "\nNo factories registered yet.\n";
        return;
    }
    
    std::cout << "\nREGISTERED PLANT FACTORIES:\n";
    std::cout << "═══════════════════════════════════════════════════\n";
    
    for (const auto& typeEntry : factories) {
        std::cout<< typeEntry.first << " Factory containing:\n";
        for (const auto& plantEntry : typeEntry.second) {
            std::cout << "   └─ " << plantEntry.first << std::endl;
        }
    }
    std::cout << "═══════════════════════════════════════════════════\n";
}

int NurseryMediator::getGreenhouseCount() const {
    return greenhouse.size();
}

int NurseryMediator::getSalesFloorCount() const {
    return salesFloor.size();
}

int NurseryMediator::getPlantCountByType(const std::string& type, bool inGreenhouse) const {
    const std::vector<Plant*>& collection = inGreenhouse ? greenhouse : salesFloor;
    int count = 0;
    
    for (auto* plant : collection) {
        if (plant->getType() == type) {
            ++count;
        }
    }
    
    return count;
}

void NurseryMediator::displaySalesStatistics() const {
    std::cout << "\n    SALES STATISTICS:" << std::endl;
    std::cout << "─────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "Total Revenue Generated: R" << std::fixed << std::setprecision(2) << totalRevenue << std::endl;
    std::cout << "Total Customers Served: " << totalCustomers << std::endl;
    
    if (totalCustomers > 0) {
        std::cout << "Average Transaction Value: R" << std::fixed << std::setprecision(2) 
                  << (totalRevenue / totalCustomers) << std::endl;
    }
    
    std::cout << "\nOrder Breakdown:" << std::endl;
    std::cout << "  Bundle Orders: " << bundleOrderCount << std::endl;
    std::cout << "  Individual Orders: " << individualOrderCount << std::endl;
    std::cout << "  Total Orders: " << (bundleOrderCount + individualOrderCount) << std::endl;
    
    std::cout << "\nCustomization Statistics:" << std::endl;
    std::cout << "  Decorative Pots Added: " << plantsWithPots << std::endl;
    std::cout << "  Gift Wrapped Items: " << plantsWithGiftWrap << std::endl;
    
    if (totalCustomers > 0) {
        std::cout << "\nCustomer Satisfaction:" << std::endl;
        std::cout << "  All transactions completed successfully" << std::endl;
        std::cout << "  100% customer satisfaction rate" << std::endl;
    } else {
        std::cout << "\nNo sales recorded this period" << std::endl;
    }
}

// Accessors
std::vector<Plant*>& NurseryMediator::getGreenhouse() { return greenhouse; }
std::vector<Plant*>& NurseryMediator::getSalesFloor() { return salesFloor; }

PlantCaretaker* NurseryMediator::getCaretaker() { return careTaker; }
