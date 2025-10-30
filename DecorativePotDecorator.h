#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H

#include "PlantDecorator.h"
#include "Plant.h"

class DecorativePotDecorator : public PlantDecorator{   
    public:
        DecorativePotDecorator(Plant* p);
        double getPrice() const override;
        void display() const override;
        Plant* clone() const override;
};

#endif
