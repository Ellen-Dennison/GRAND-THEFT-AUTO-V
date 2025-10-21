

#ifndef GRAND_THEFT_AUTO_V_ROSEFACTORY_H
#define GRAND_THEFT_AUTO_V_ROSEFACTORY_H

#include "PlantFactory.h"
#include <string>

class RoseFactory : public PlantFactory{
public:
     Plant* createPlant() override;
     std::string getFactoryType() const override;

};


#endif //GRAND_THEFT_AUTO_V_ROSEFACTORY_H
