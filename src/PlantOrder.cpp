#include "PlantOrder.h"
#include <iostream>
using namespace std;

// Default constructor
PlantOrder::PlantOrder() {
    plant = NULL;
    hasGiftWrapping = false;
    hasDecorativePot = false;
    customerName = "";
}

// Display order details
void PlantOrder::display() {
    cout << "\n🧾 --- Plant Order Summary ---" << endl;
    cout << "👤 Customer Name: " << customerName << endl;

    if (plant)
        cout << "🌿 Plant: " << plant->getName() 
             << " (" << plant->getType() << ")" << endl;
    else
        cout << "🌿 Plant: [No plant assigned]" << endl;

    cout << "🪴 Decorative Pot: " 
         << (hasDecorativePot ? "Yes" : "No") << endl;
    cout << "🎁 Gift Wrapping: " 
         << (hasGiftWrapping ? "Yes" : "No") << endl;
    cout << "💰 Price: " 
         << (plant ? to_string(plant->getPrice()) : "N/A") << endl;
    cout << "-------------------------------\n" << endl;
}
