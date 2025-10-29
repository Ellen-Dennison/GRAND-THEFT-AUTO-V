#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
#include <string>
//#include <map>

class PlantFactory {
public:
    virtual ~PlantFactory() {}
    virtual Plant* createPlant() = 0;
    virtual std::string getFactoryType() const = 0;
};

#endif
