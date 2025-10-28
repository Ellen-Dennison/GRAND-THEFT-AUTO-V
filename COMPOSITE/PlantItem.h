#ifndef PLANTITEM_H
#define PLANTITEM_H
#include "PlantComponent.h"

class PlantItem:public PlantComponent
{
  private:
      Plant* plant;

  public:
      PlantItem(Plant* p);
      ~PlantItem();
      void display();
      double getTotalValue();
      int getCount();  


};

#endif