#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include <iostream>
#include <string>

class OrderBuilder{
protected:
    PlantOrder* order;
public:
    OrderBuilder();
    virtual ~OrderBuilder();
    OrderBuilder* setCustomer(std::string name);
    OrderBuilder* setPlant(Plant* plant);
    OrderBuilder* addDecorativePot();
    OrderBuilder* addGiftWrapping()
    PlantOrder* build();
}

#endif
