#include "Customer.h"


Customer::Customer(string n, double b)
    : name(n), budget(b) {}

string Customer::getName() const { return name; }
double Customer::getBudget() const { return budget; }


void Customer::browseSalesFloor(vector<Plant*>& salesFloor) {
    cout << "\n👀 " << name << " is browsing the sales floor..." << endl;

    if (salesFloor.empty()) {
        cout << "There are currently no plants available for sale.\n";
        return;
    }

    for (auto* plant : salesFloor) {
        cout << "🪴 " << plant->getName() << " (" << plant->getType()
             << ") - Price: R" << plant->getPrice() << endl;
    }
}


bool Customer::canAfford(double price) const {
    if (budget >= price)
        return true;
    return false;
}


void Customer::askForRecommendation() {
    cout << name << ": Can you recommend a plant for me?" << endl;
}


void Customer::expressInterest(string plantName) {
    cout  << name << ":  " <<"I'd like to know more about the plant " <<plantName<< endl;
}


void Customer::requestCustomisation(string customType) {
    cout << name << ": I'd like to add " << customType
         << " to my plant purchase, please." << endl;
}


void Customer::makePurchase(double amount) {
    cout << "💰 " << name << " is attempting to make a purchase of R" << amount << "..." << endl;

    if (amount > budget) {
        cout << "❌ " << name << " cannot afford this purchase. (Budget: R" << budget << ")\n";
        return;
    }

    budget -= amount;
    cout << "✅ Purchase successful! Remaining budget: R" << budget << endl;
}
