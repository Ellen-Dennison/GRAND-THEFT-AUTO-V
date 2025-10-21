#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H
#include "PlantDecorator.h"
#include "Plant.h"

class DecorativePotDecorator: public PlantDecorator{
    public:
            DecorativePotDecorator(Plant *wrappedPlant);
            void printPlant();
};
#endif