#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H
#include <iostream>
#include "../Plant.h"

class PlantDecorator
{
  
protected:
    Plant* wrappedPlant;

public:
    PlantDecorator(Plant* p);
    ~PlantDecorator();
    std::string getName();
    std::string getType();
    virtual double getPrice() = 0;
    virtual void display() = 0;
    virtual Plant* clone() const = 0;
  
};

#endif