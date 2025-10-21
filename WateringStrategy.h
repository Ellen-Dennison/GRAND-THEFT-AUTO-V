#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "Plant.h"

#include <iostream>
using namespace std;

class Plant;
class WateringStrategy{
    
  virtual void water(Plant* plant)=0;
  virtual void getWateringSchedule()=0;
 // virtual ~WateringStrategy();
    
    
    
};







#endif