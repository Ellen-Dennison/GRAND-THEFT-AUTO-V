#ifndef HERB_H
#define HERB_H
#include "BiWeeklyWateringStrategy.h"
#include "Plant.h"
#include <iostream>

class Herb:public Plant
{   
    public:
    Herb(std::string name, double price);
    Plant* clone() const;
};


#endif