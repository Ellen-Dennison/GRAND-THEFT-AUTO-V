#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H
#include "PlantFactory.h"

class FlowerFactory: public PlantFactory
{
   private:
   Plant* plant;//!CHANGES
   
   public:
   virtual Plant* createPlant();
   virtual std::string getFactoryType();

};

#endif