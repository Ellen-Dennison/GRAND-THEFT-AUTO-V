#ifndef PLANT_H
#define PLANT_H


#include "PlantMemento.h"
#include "WateringStrategy.h"
#include <iostream>
using namespace std;
#include <string>

class WateringStrategy;
class Plant{
  
  string name;
  string type;
  double price;
  WateringStrategy* strategy;
  
  public:
  
  Plant(string name,string type,double price);
  ~Plant();
  PlantMemento* createMemento();
  void setWateringStrategy(WateringStrategy* strategy);
  string getName();
  string getType();
  double getPrice();
    
    
};




#endif