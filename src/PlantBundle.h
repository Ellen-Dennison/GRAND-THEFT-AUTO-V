#ifndef PLANTBUNDLE_H
#define PLANTBUNDLE_H
#include <iostream>
#include <vector>

#include "PlantComponent.h"

class PlantBundle:public PlantComponent
{  
  private:
        std::string bundleName;
        std::vector<PlantComponent*> items;
        double discount;

  public:
        PlantBundle(std::string bundleName, double discount);
        ~PlantBundle();
        void add( PlantComponent* item );
        void remove( PlantComponent* item );
        void display() const override;
        double getTotalValue() const override;
        virtual int getCount();
    
};

#endif