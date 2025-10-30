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
      virtual void display();
      virtual double getTotalValue();
      virtual int getCount();  


};

#endif