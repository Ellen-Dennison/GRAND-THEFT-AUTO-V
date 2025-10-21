#ifndef PLANTORDER_H
#define PLANTORDER_H

#include <iostream>
#include <string>

class PlantOrder{
public:
    Plant* plant;
    bool hasDecorativePot;
    bool hasGiftWrapping;
    std::string customerName;

    PlantOrder();
    void display()const;
};

#endif
