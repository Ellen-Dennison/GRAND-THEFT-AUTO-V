/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H

#include "PlantFactory.h"
#include "Succulent.h"

class SucculentFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string succulentName;
    double succulentPrice;

public:
    SucculentFactory(std::string, double price);
    ~SucculentFactory();
    Plant* createPlant() override;
    std::string getFactoryType() const override;
};

#endif
