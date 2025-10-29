#ifndef TREETFACTORY_H
#define TREEFACTORY_H
#include "PlantFactory.h"
#include "../Tree.h"

class TreeFactory: public PlantFactory
{
   private:
   std::string name;//!CHANGES
   std::string type;//!CHANGES
   std::string plant;//!CHANGES
   double price;//!CHANGES

   public:
   virtual Plant* createPlant(std::string name, std::string type, double price);
   virtual std::string getFactoryType();

};

#endif