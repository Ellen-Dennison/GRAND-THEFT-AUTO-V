
#ifndef GRAND_THEFT_AUTO_V_NURSERYMEDIATOR_H
#define GRAND_THEFT_AUTO_V_NURSERYMEDIATOR_H

#include "Subject.h"

#include <vector>
#include <map>
#include <string>

class Plant;
class PlantFactory;
class PlantCaretaker;
class Customer;

class NurseryMediator : public Subject {
private:
    std::vector<Plant*> greenhouse;
    std::vector<Plant*> salesFloor;
    std::map<std::string, PlantFactory*> factories;
    PlantCaretaker* caretaker;

public:
    NurseryMediator();
    ~NurseryMediator();




};


#endif //GRAND_THEFT_AUTO_V_NURSERYMEDIATOR_H
