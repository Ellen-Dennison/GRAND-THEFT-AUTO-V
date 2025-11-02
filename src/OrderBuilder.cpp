#include "OrderBuilder.h"
#include "GiftWrappingDecorator.h"
#include "DecorativePotDecorator.h"

OrderBuilder::OrderBuilder() {
    order = new PlantOrder();
    currentBundle = NULL;
    currentComponent = NULL;
}

OrderBuilder::~OrderBuilder() {
    if (order) {
        delete order;
        order = NULL;
    }
    if (currentBundle) {
        delete currentBundle;
        currentBundle = NULL;
    }
}

OrderBuilder* OrderBuilder::setCustomer(std::string name) {
    order->setCustomerName(name);
    return this;
}

//For a single plant with optional decorators
OrderBuilder* OrderBuilder::setPlant(Plant* plant, bool decorativePot, bool giftWrap) {
    if (currentBundle != NULL) {
        std::cerr << "Warning: Cannot set single plant while building a bundle!" << std::endl;
        return this;
    }
    if (currentComponent != NULL) {
        std::cerr << "Warning: Plant already set! Previous plant will be replaced." << std::endl;
    }
    
    //Apply decorators to the plant if requested
    Plant* decoratedPlant = plant;
    
    if (decorativePot) {
        decoratedPlant = new DecorativePotDecorator(decoratedPlant);
    }
    
    if (giftWrap) {
        decoratedPlant = new GiftWrappingDecorator(decoratedPlant);
    }
    
    //Wrap in PlantItem
    currentComponent = new PlantItem(decoratedPlant);
    return this;
}

//For building a plant bundle
OrderBuilder* OrderBuilder::startBundle(std::string bundleName, double discount) {
    if (currentBundle != NULL) {
        std::cerr << "Warning: Bundle already started!" << std::endl;
        return this;
    }
    if (currentComponent != NULL) {
        std::cerr << "Warning: Starting bundle will replace the current plant." << std::endl;
    }
    currentBundle = new PlantBundle(bundleName, discount);
    return this;
}

//Add a plant to the current bundle with optional decorators
OrderBuilder* OrderBuilder::addPlantToBundle(Plant* plant, bool decorativePot, bool giftWrap) {
    if (currentBundle == NULL) {
        std::cerr << "Error: No bundle started yet" << std::endl;
        return this;
    }
    
    //Apply decorators if needed
    Plant* decoratedPlant = plant;
    
    if (decorativePot) {
        decoratedPlant = new DecorativePotDecorator(decoratedPlant);
    }
    
    if (giftWrap) {
        decoratedPlant = new GiftWrappingDecorator(decoratedPlant);
    }
    
    //Wrap in PlantItem and add to bundle
    PlantItem* item = new PlantItem(decoratedPlant);
    currentBundle->add(item);
    return this;
}

//Finish the bundle
OrderBuilder* OrderBuilder::finishBundle() {
    if (currentBundle == NULL) {
        std::cerr << "Error: No bundle to finish!" << std::endl;
        return this;
    }
    currentComponent = currentBundle;
    currentBundle = NULL;
    return this;
}

//build
PlantOrder* OrderBuilder::build() {
    if (currentBundle != NULL) {
        std::cerr << "Warning: Bundle not finished! Call finishBundle() before build()." << std::endl;
        finishBundle();
    }
    
    if (currentComponent == NULL) {
        std::cerr << "Warning: No plant or bundle set for this order!" << std::endl;
    } else {
        order->setPlantComponent(currentComponent);
        currentComponent = NULL;
    }
    
    PlantOrder* finishedOrder = order;
    order = new PlantOrder();
    
    return finishedOrder;
}

//is a bundle currently being built??
bool OrderBuilder::isBuildingBundle() const {
    return currentBundle != NULL;
}

void OrderBuilder::reset() {
    if (order) {
        delete order;
    }
    if (currentBundle) {
        delete currentBundle;
    }
    
    order = new PlantOrder();
    currentBundle = NULL;
    currentComponent = NULL;
}
