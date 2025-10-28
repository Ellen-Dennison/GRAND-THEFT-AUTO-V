#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H
#include "PlantDecorator.h"

class GiftWrappingDecorator:public PlantDecorator
{
    private:
    double price;

    public:
        GiftWrappingDecorator(Plant* plant);
        virtual double getPrice();
        virtual void display();
        virtual Plant* clone() const;
};

#endif