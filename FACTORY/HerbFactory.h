#ifndef HERBFACTORY_H
#define HERBFACTORY_H
#include "PlantFactory.h"
#include "../Herb.h"

class HerbFactory: public PlantFactory
{
   private:
   std::string name;//!CHANGES
   std::string type;//!CHANGES
   std::string plant;//!CHANGES
   double price;//!CHANGES
   
   public:
   virtual Plant* createPlant(std::string name, double price);
   virtual std::string getFactoryType();

};

#endif