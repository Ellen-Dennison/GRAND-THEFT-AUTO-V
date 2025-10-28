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
        PlantBundle(std::string name, double discount);
        ~PlantBundle();
        void add();
        void remove();
        void display();
        double getTotalValue();
        int getCount();
    
};

#endif