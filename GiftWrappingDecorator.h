#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H
#include "PlantDecorator.h"
#include "Plant.h"

class GiftWrappingDecorator: public PlantDecorator{
    public:
            GiftWrappingDecorator(Plant* wrappedPlant);
            void printPlant();
};
#endif