#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H
#include "Plant.h"
#include <iostream>

class PlantComponent
{   
    private:
    std::string Name;

    public:
        virtual void display() const = 0;
        virtual double getTotalValue() const = 0;
        virtual int getCount() const  = 0;
        virtual ~PlantComponent() {};

};

#endif