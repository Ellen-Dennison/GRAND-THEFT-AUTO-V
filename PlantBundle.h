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
        double discountPrice;//!CHANGES
        double price;//!CHANGES

  public:
        PlantBundle(std::string bundleName, double discount);
        ~PlantBundle();
        void add( PlantComponent* item );
        void remove( PlantComponent* item );
        virtual void display();
        virtual double getTotalValue();
        double getNonDiscount();//!CHANGES
        virtual int getCount();
    
};

#endif