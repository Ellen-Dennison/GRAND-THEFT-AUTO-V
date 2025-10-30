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
      void display() const override;
      double getTotalValue() const override;
      int getCount() const override;  
      ~PlantItem()
      {
        if (plant != nullptr)
        {delete plant;}
      }


};

#endif