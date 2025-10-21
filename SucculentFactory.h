

#ifndef GRAND_THEFT_AUTO_V_SUCCULENTFACTORY_H
#define GRAND_THEFT_AUTO_V_SUCCULENTFACTORY_H
#include "PlantFactory.h"
#include <string>

class SucculentFactory : public PlantFactory{
public:
    Plant* createPlant() override;
    std::string getFactoryType() const override;

};


#endif //GRAND_THEFT_AUTO_V_SUCCULENTFACTORY_H
