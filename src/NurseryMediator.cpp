#include "NurseryMediator.h"
#include "FlowerFactory.h"
#include "SucculentFactory.h"
#include "TreeFactory.h"
#include "HerbFactory.h"
#include "PlantMemento.h"
#include <algorithm>
#include <iostream>


NurseryMediator::NurseryMediator() {
    plantIdCounter = 0;
    careTaker = new PlantCaretaker();

    // ✅ Each factory needs name and base price
    factories["Flower"]    = new FlowerFactory("Flower", 50.0);
    factories["Succulent"] = new SucculentFactory("Succulent", 35.0);
    factories["Tree"]      = new TreeFactory("Tree", 120.0);
    factories["Herb"]      = new HerbFactory("Herb", 25.0);

    cout << "🏗️ NurseryMediator initialized.\n";
}

NurseryMediator::~NurseryMediator() {
    for (auto* plant : greenhouse)
        delete plant;
    for (auto* plant : salesFloor)
        delete plant;

    delete careTaker;

    for (auto& entry : factories)
        delete entry.second;

    factories.clear();
    greenhouse.clear();
    salesFloor.clear();

    cout << "🏁 NurseryMediator destroyed.\n";
}

// 🌱 Add new plant
void NurseryMediator::addNewPlant(string plantType) {
    if (factories.find(plantType) == factories.end()) {
        std::cout << "❌ Unknown plant type: " << plantType << std::endl;
        return;
    }

    // ✅ createPlant() takes no arguments
    Plant* newPlant = factories[plantType]->createPlant();

    // Give each plant a name using counter
    ++plantIdCounter;
    newPlant->setPrice(newPlant->getPrice() + (plantIdCounter * 2)); // optional differentiation

    greenhouse.push_back(newPlant);

    std::cout << "🌿 Added new " << plantType << " (" << newPlant->getName() << ") to greenhouse.\n";
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
    std::cout << "\n🌾 Harvesting ready plants...\n";
    auto it = greenhouse.begin();
    while (it != greenhouse.end()) {
        Plant* plant = *it;
        if (plant->isReadyForSale()) {
            std::cout << "🪴 " << plant->getName() << " moved to sales floor.\n";
            salesFloor.push_back(plant);
            it = greenhouse.erase(it);
        } else {
            ++it;
        }
    }
}

// 💾 Save healthy states (Memento)
void NurseryMediator::saveHealthyStates() {
    std::cout << "\n💾 Saving healthy plant states...\n";
    for (auto* plant : greenhouse) {
        if (plant->getHealth() > 70) {
            // ✅ Pass plant name + memento
            careTaker->saveMemento(plant->getName(), plant->createMemento());
            std::cout << "📸 Saved state for " << plant->getName() << endl;
        }
    }
}

// 🧪 Check for wilting plants
void NurseryMediator::checkForWiltingPlants() {
    cout << "\n🧪 Checking for wilting plants...\n";
    for (auto* plant : greenhouse) {
        if (plant->getHealth() < 40) {
            std::cout << "⚠️ " << plant->getName() << " is wilting! Health = "
                 << plant->getHealth() << std::endl;
        }
    }
}

// 🛍️ Process customer orders
PlantOrder* NurseryMediator::processCustomerOrder(std::string cusName, std::string plantType,
                                                  bool wantsPot, bool wantsWrapping) {
    std::cout << "\n🛍️ Processing order for " << cusName << ": " << plantType << std::endl;

    for (auto it = salesFloor.begin(); it != salesFloor.end(); ++it) {
        Plant* plant = *it;
        if (plant->getType() == plantType) {
            PlantOrder* order = new PlantOrder();
            order->customerName = cusName;
            order->plant = plant;
            order->hasDecorativePot = wantsPot;
            order->hasGiftWrapping = wantsWrapping;

            std::cout << "✅ Order created for " << cusName << " (" << plant->getName() << ")\n";
            salesFloor.erase(it);
            return order;
        }
    }

    std::cout << "❌ No " << plantType << " plants available.\n";
    return NULL;
}

// 👀 Customer browsing
void NurseryMediator::customerBrowsingInteraction(Customer* customer) {
    std::cout << "\n👀 " << customer->getName() << " is browsing the sales floor...\n";
    customer->browseSalesFloor(salesFloor);
}

// 📊 Inventory display
void NurseryMediator::displayInventory() {
   std::cout << "\n📊 Nursery Inventory Summary\n";
    std::cout << "---------------------------------\n";
    std::cout << "🌱 Greenhouse: " << greenhouse.size() << " plants\n";
    std::cout << "🪴 Sales Floor: " << salesFloor.size() << " plants\n";

    std::cout << "\nGreenhouse Plants:\n";
    for (auto* plant : greenhouse) {
        std::cout << "  - " << plant->getName()
             << " (" << plant->getType()
             << "), Health: " << plant->getHealth()
             << ", Age: " << plant->getAge() << std::endl;
    }

    std::cout << "\nSales Floor Plants:\n";
    for (auto* plant : salesFloor) {
        std::cout << "  - " << plant->getName()
             << " (" << plant->getType()
             << "), Price: " << plant->getPrice() << std::endl;
    }
}

// Accessors
vector<Plant*>& NurseryMediator::getGreenhouse() { return greenhouse; }
vector<Plant*>& NurseryMediator::getSalesFloor() { return salesFloor; }
