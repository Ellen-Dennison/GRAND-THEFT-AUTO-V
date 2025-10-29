#ifndef HERB_H
#define HERB_H
#include <iostream>
#include "Plant.h"

class Herb:public Plant
{    
    public:
    Herb(std::string name, double price);
    virtual ~Herb() {};
    Plant* clone() const override;
};


#endif
