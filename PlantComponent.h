#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H
#include "Plant.h"

class PlantComponent
{
    public:
        virtual void display() = 0;
        virtual double getTotalValue() = 0;
        virtual int getCount() = 0;

};

#endif