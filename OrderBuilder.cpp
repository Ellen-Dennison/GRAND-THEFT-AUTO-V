#include "OrderBuilder.h"
using namespace std;

// 🌱 Constructor
OrderBuilder::OrderBuilder() {
    order = new PlantOrder();
}

// 🧹 Destructor
OrderBuilder::~OrderBuilder() {
    if (order) {
        delete order;
        order = NULL;
    }
}

// 👤 Set the customer name
OrderBuilder* OrderBuilder::setCustomer(string name) {
    order->customerName = name;
    return this; // enables method chaining
}

// 🌿 Set the plant being ordered
OrderBuilder* OrderBuilder::setplant(Plant* plant) {
    order->plant = plant;
    return this;
}

// 🪴 Add a decorative pot
OrderBuilder* OrderBuilder::addDecorativePot() {
    order->hasDecorativePot = true;
    return this;
}

// 🎁 Add gift wrapping
OrderBuilder* OrderBuilder::addGiftWrapping() {
    order->hasGiftWrapping = true;
    return this;
}

// ✅ Finalize and return the completed order
PlantOrder* OrderBuilder::build() {
    PlantOrder* finishedOrder = order;
    order = NULL; // avoid double deletion
    return finishedOrder;
}
