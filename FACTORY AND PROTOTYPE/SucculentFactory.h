#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H
#include "PlantFactory.h"
#include "../Succulent.h"

class SucculentFactory: public PlantFactory
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