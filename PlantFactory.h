
#ifndef GRAND_THEFT_AUTO_V_PLANTFACTORY_H
#define GRAND_THEFT_AUTO_V_PLANTFACTORY_H

#include <string>
class Plant;

class PlantFactory {
public:
    virtual ~PlantFactory(){}
    virtual Plant* createPlant() = 0;
    virtual std::string getFactoryType() const = 0;
};


#endif //GRAND_THEFT_AUTO_V_PLANTFACTORY_H
