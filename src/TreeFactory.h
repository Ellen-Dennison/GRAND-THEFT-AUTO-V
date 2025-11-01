/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "PlantFactory.h"
#include "Tree.h"

class TreeFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string treeName;
    double treePrice;

public:
    TreeFactory(std::string name, double price);
    ~TreeFactory();
    Plant* createPlant() override;
    std::string getFactoryType() const override;
};

#endif
