#ifndef PLANTITEM_H
#define PLANTITEM_H
#include "PlantComponent.h"

class PlantItem:public PlantComponent
{
  private:
      Plant* plant;

  public:
      PlantItem(Plant* p);
      virtual ~PlantItem();
      std::string getName() const;
      virtual void display() const;
      virtual double getTotalValue() const;
      virtual int getCount() const; 


};

#endif