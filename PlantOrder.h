#ifndef PLANTORDER_H
#define PLANTORDER_H

#include <string>
#include "Plant.h"

using namespace std;


class PlantOrder{
    
    public:
    
    Plant* plant;
    bool hasGiftWrapping;
    string customerName;
    bool hasDecorativePot;
    PlantOrder();
    void display();
};




#endif