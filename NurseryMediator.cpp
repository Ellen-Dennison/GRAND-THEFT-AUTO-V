#include "NurseryMediator.h"

NurseryMediator::NurseryMediator() {
    plantIdCounter = 0;
    careTaker = new PlantCaretaker();

  

    cout << "️ NurseryMediator initialized.\n";
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

    cout << " NurseryMediator destroyed.\n";
}


void NurseryMediator::addNewPlant(string plantType) {
    if (factories.find(plantType) == factories.end()) {
        cout << "Unknown plant "<< plantType << endl;
        return;
    }

    Plant* newPlant = factories[plantType]->createPlant("Plant_" + to_string(++plantIdCounter));
    greenhouse.push_back(newPlant);

    cout << "🌿 Added new " << plantType << " (" << newPlant->getName() << ") to the greenhouse.\n";
}

//  Apply care (watering, sunlight, fertilizing) to all greenhouse plants
void NurseryMediator::careForGreenhouse() {
    cout << "\n💧 Caring for greenhouse plants...\n";

    for (auto* plant : greenhouse) {
        plant->water();
        plant->provideSunlight();
        plant->fertilize();
        cout << "✅ " << plant->getName() << " cared for.\n";
    }
}

// ⏳davance time (simulate plant growth)
void NurseryMediator::advanceTime(int weeks) {
    cout << "\n⏳ Advancing time by " << weeks << " weeks...\n";

    for (auto* plant : greenhouse) {
        for (int i = 0; i < weeks; ++i)
            plant->grow();
    }

    harvestMaturePlants();
}

// 🌾 Move ready plants from greenhouse to sales floor
void NurseryMediator::harvestMaturePlants() {
    cout << "\n🌾 Harvesting plants ready for sale...\n";

    auto it = greenhouse.begin();
    while (it != greenhouse.end()) {
        Plant* plant = *it;
        if (plant->isReadyForSale()) {
            cout << "🪴 " << plant->getName() << " is ready for sale and moved to the sales floor.\n";
            salesFloor.push_back(plant);
            it = greenhouse.erase(it);
        } else {
            ++it;
        }
    }
}

// 💾 Save the state of all healthy plants (Memento Pattern)
void NurseryMediator::saveHealthyStates() {
    cout << "\n💾 Saving healthy plant states...\n";

    for (auto* plant : greenhouse) {
        if (plant->getHealth() > 70) { // example condition for “healthy”
            careTaker->saveMemento(plant->createMemento());
            cout << "📸 Saved state for " << plant->getName() << endl;
        }
    }
}

// 🧪 Check for wilting or unhealthy plants
void NurseryMediator::checkForWiltingPlants() {
    cout << "\n🧪 Checking for wilting plants...\n";

    for (auto* plant : greenhouse) {
        if (plant->getHealth() < 40) {
            cout << "⚠️ " << plant->getName() << " is wilting! Health = " 
                 << plant->getHealth() << endl;
        }
    }
}

// 🛍️ Process a customer order (creates a PlantOrder)
PlantOrder* NurseryMediator::processCustomerOrder(string cusName, string plantType, bool wantsPot, bool wantsWrapping) {
    cout << "\n️ Processing order for " << cusName << ": " << plantType << endl;

    for (auto it = salesFloor.begin(); it != salesFloor.end(); ++it) {
        Plant* plant = *it;
        if (plant->getType() == plantType) {
            // Create and return order
            PlantOrder* order = new PlantOrder();
            order->customerName = cusName;
            order->plant = plant;
            order->hasDecorativePot = wantsPot;
            order->hasGiftWrapping = wantsWrapping;

            cout << "✅ Order created for " << cusName << " (" << plant->getName() << ")\n";
            salesFloor.erase(it);
            return order;
        }
    }

    cout << "❌Sorry, no " << plantType << " available right now.\n";
    return NULL;
}

// 👀 Customer browsing plants for sale
void NurseryMediator::customerBrowsingInteraction(Customer* customer) {
    cout << "\n" << customer->getName() << " is browsing the sales floor...\n";
    customer->browseSalesFloor(salesFloor);
}

// 📊 Display current inventory of greenhouse and sales floor
void NurseryMediator::displayInventory() {
    cout << "\n Nursery Inventory Summary\n";
    cout << "---------------------------------\n";
    cout << "Greenhouse: " << greenhouse.size() << " plants\n";
    cout << " Sales Floor: " << salesFloor.size() << " plants\n";

    cout << "\nGreenhouse Plants:\n";
    for (auto* plant : greenhouse) {
        cout << "  - " << plant->getName() << " (" << plant->getType()
             << "), Health: " << plant->getHealth()
             << ", Age: " << plant->getAge() << endl;
    }

    cout << "\nSales Floor Plants:\n";
    for (auto* plant : salesFloor) {
        cout << "  - " << plant->getName() << " (" << plant->getType()
             << "), Price: " << plant->getPrice() << endl;
    }
}

// ✅ Accessor methods
vector<Plant*>& NurseryMediator::getGreenhouse() {
    return greenhouse;
}

vector<Plant*>& NurseryMediator::getSalesFloor() {
    return salesFloor;
}




