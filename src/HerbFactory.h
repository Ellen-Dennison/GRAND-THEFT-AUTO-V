/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "PlantFactory.h"
#include "Herb.h"

class HerbFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string herbName;
    double herbPrice;

public:
    HerbFactory(std::string name, double price);
    ~HerbFactory();
    Plant* createPlant() override;
    std::string getFactoryType() const override;
};

#endif
