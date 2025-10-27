#ifndef HERBFACTORY_H
#define HERBFACTORY_H
#include "PlantFactory.h"

class HerbFactory: public PlantFactory
{
   private:
   Plant* plant;//!CHANGES
   
   public:
   virtual Plant* createPlant();
   virtual std::string getFactoryType();

};

#endif