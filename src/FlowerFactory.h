/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H

#include "PlantFactory.h"
#include "Flower.h"

class FlowerFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string flowerName;
    double flowerPrice;

public:
    FlowerFactory(std::string name, double price);
    ~FlowerFactory();
    Plant* createPlant() override;
    std::string getFactoryType() const override;
};

#endif
