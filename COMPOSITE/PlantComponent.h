#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H
#include "../Plant.h"

class PlantComponent
{
    public:
        ~PlantComponent();
        void display();
        double getTotalValue();
        int getCount();

};

#endif