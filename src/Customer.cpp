#include "Customer.h"


Customer::Customer(std::string n, double b)
    : name(n), budget(b) {}

std::string Customer::getName() const { return name; }
double Customer::getBudget() const { return budget; }


void Customer::browseSalesFloor(std::vector<Plant*>& salesFloor) {
    std::cout << name << " is browsing the sales floor..." << std::endl;

    if (salesFloor.empty()) {
        std::cout << "There are currently no plants available for sale.\n";
        return;
    }

    for (auto* plant : salesFloor) {
        std::cout  << plant->getName() << " (" << plant->getType()
             << ") - Price: R" << plant->getPrice() << std::endl;
    }
}


bool Customer::canAfford(double price) const {
    if (budget >= price)
        return true;
    return false;
}


void Customer::askForRecommendation() {
    std::cout << name << ": Can you recommend a plant for me?" << std::endl;
}


void Customer::expressInterest(std::string plantName) {
    std::cout  << name << ":  " <<"I'd like to know more about the plant " <<plantName<< std::endl;
}


void Customer::requestCustomisation(std::string customType) {
    std::cout << name << ": I'd like to add " << customType
         << " to my plant purchase, please." << std::endl;
}


void Customer::makePurchase(double amount) {
    
    std::cout << name << " is attempting to make a purchase of R" << amount << "..." << std::endl;

    if (amount > budget) {
        std::cout << name << " cannot afford this purchase. (Budget: R" << budget << ")\n";
        return;
    }

    budget -= amount;
    std::cout << "✅ Purchase successful! Remaining budget: R" << budget << std::endl;
}
