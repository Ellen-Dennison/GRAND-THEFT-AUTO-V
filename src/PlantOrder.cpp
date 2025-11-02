#include "PlantOrder.h"
#include <iostream>
#include <iomanip>
#include <ctime>

PlantOrder::PlantOrder() {
    plantComponent = NULL;
    customerName = "";
}

PlantOrder::~PlantOrder() {
    if (plantComponent != NULL) {
        delete plantComponent;
        plantComponent = NULL;
    }
}

// Setter methods
void PlantOrder::setCustomerName(const std::string& name) {
    customerName = name;
}

void PlantOrder::setPlantComponent(PlantComponent* component) {
    plantComponent = component;
}

// Getter methods
std::string PlantOrder::getCustomerName() const {
    return customerName;
}

PlantComponent* PlantOrder::getPlantComponent() const {
    return plantComponent;
}

// Display order details
void PlantOrder::display() {
    //Get current timestamp
    time_t timestamp;
    time(&timestamp);
    
    std::cout << "\n🧾 =================================" << std::endl;
    std::cout << "       PLANT ORDER SUMMARY" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "👤 Customer: " << customerName << std::endl;
    std::cout << "📅 Date: " << ctime(&timestamp);
    std::cout << "-----------------------------------" << std::endl;

    if (plantComponent) {
        // Display order type (Bundle or Single Item)
        int itemCount = plantComponent->getCount();
        if (itemCount > 1) {
            std::cout << "📦 Order Type: Bundle (" << itemCount << " items)" << std::endl;
        } else {
            std::cout << "🌱 Order Type: Single Item" << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
        
        //Display the component details
        plantComponent->display();
        
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "📊 ORDER SUMMARY:" << std::endl;
        std::cout << "   Total Items: " << itemCount << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "   💰 TOTAL PRICE: R" << plantComponent->getTotalValue() << std::endl;
    } else {
        std::cout << "⚠️  No items in order" << std::endl;
    }
    
    std::cout << "===================================" << std::endl;
    std::cout << "   Thank you for your purchase! 🌿" << std::endl;
    std::cout << "===================================" << std::endl;
}
