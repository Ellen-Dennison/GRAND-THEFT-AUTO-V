
#ifndef GRAND_THEFT_AUTO_V_BAOBABFACTORY_H
#define GRAND_THEFT_AUTO_V_BAOBABFACTORY_H


#include "PlantFactory.h"
#include <string>

class BaobabFactory : public PlantFactory{
public:
    Plant* createPlant() override;
    std::string getFactoryType() const override;

};


#endif //GRAND_THEFT_AUTO_V_BAOBABFACTORY_H
