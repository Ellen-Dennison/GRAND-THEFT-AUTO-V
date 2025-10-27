#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H
#include "PlantFactory.h"

class SucculentFactory: public PlantFactory
{
   private:
   Plant* plant;//!CHANGES
   
   public:
   virtual Plant* createPlant();
   virtual std::string getFactoryType();

};

#endif