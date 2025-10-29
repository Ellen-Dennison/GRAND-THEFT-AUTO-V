#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H
#include "../Plant.h"

class PlantFactory
{

   public:
   virtual Plant* createPlant(std::string name, std::string type, double price) = 0;//!CHANGES
   virtual std::string getFactoryType() = 0;

};

#endif