#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"
using namespace std;

class Customer {
private:
    string name;
    double budget;

public:
    
    Customer(string n, double b);

  
    string getName() const;
    double getBudget() const;

   
    void browseSalesFloor(vector<Plant*>& salesFloor);
    bool canAfford(double price) const;

  
    void askForRecommendation();
    void expressInterest(string plantName);
    void requestCustomisation(string customType);
    void makePurchase(double amount);
};

#endif
