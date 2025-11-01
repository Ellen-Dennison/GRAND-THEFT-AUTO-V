/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H

#include "PlantDecorator.h"
#include "Plant.h"

class GiftWrappingDecorator : public PlantDecorator{   
    public:
        GiftWrappingDecorator(Plant* p);
        double getPrice() const override;
        void display() const override;
        Plant* clone() const override;
};

#endif
