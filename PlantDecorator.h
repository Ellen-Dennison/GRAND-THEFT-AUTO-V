#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <iostream>
#include <string>
#include "Plant.h"

class PlantDecorator : public Plant
{
  
protected:
    Plant* wrappedPlant;

public:
    PlantDecorator(Plant* p);
    virtual ~PlantDecorator();
    virtual std::string getName()const override;
    virtual std::string getType() const override;
    virtual double getPrice() const override;
    void display()const override;
    Plant* clone() const override = 0;
  
};

#endif
