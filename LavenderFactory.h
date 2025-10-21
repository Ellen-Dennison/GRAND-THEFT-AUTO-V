
#ifndef GRAND_THEFT_AUTO_V_LAVENDERFACTORY_H
#define GRAND_THEFT_AUTO_V_LAVENDERFACTORY_H

#include "PlantFactory.h"
#include <string>

class LavenderFactory : public PlantFactory{
public:
    Plant* createPlant() override;
    std::string getFactoryType() const override;

};

#endif //GRAND_THEFT_AUTO_V_LAVENDERFACTORY_H
