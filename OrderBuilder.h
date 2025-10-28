#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H




#include <iostream>
#include "PlantOrder.h"

#include <string>

using namespace std;

class OrderBuilder{
    
    protected:
    
    PlantOrder* order;
    
    public:
    
    OrderBuilder();
    ~OrderBuilder();
    OrderBuilder* setCustomer(string name);
    OrderBuilder* setplant(Plant* plant);
    OrderBuilder* addDecorativePot();
    OrderBuilder* addGiftWrapping();
    PlantOrder* build();
};









#endif