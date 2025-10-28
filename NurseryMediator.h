#ifndef NURSERY_MEDIATOR_H
#define NURSERY_MEDIATOR_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Plant.h"
#include "PlantFactory.h"
#include "PlantCaretaker.h"
#include "Customer.h"
#include "PlantOrder.h"

using namespace std;

class NurseryMediator {
private:
    vector<Plant*> greenhouse;
    vector<Plant*> salesFloor;
    map<string, PlantFactory*> factories;
    PlantCaretaker* careTaker;
    int plantIdCounter;

public:
    NurseryMediator();
    ~NurseryMediator();

    void addNewPlant(string plantType);
    void careForGreenhouse();
    void advanceTime(int weeks);
    void harvestMaturePlants();
    void saveHealthyStates();
    void checkForWiltingPlants();
    PlantOrder* processCustomerOrder(string cusName, string plantType, bool wantsPot, bool wantsWrapping);
    void customerBrowsingInteraction(Customer* customer);
    void displayInventory();

    vector<Plant*>& getGreenhouse();
    vector<Plant*>& getSalesFloor();
};

#endif





