#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H
#include "PlantFactory.h"
#include "../Flower.h"

class FlowerFactory: public PlantFactory
{
   private:
   std::string name;//!CHANGES
   std::string type;//!CHANGES
   std::string plant;//!CHANGES
   double price;//!CHANGES
   
   public:
   virtual Plant* createPlant();
   virtual std::string getFactoryType();

};

#endif