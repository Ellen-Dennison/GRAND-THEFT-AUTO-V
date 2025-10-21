#ifndef WEEKLYWATERINGSTRATEGY_H
#define WEEKLYWATERINGSTRATEGY_H

#include "WateringStrategy.h"

#include "Plant.h"

using namespace std;

class WeeklyWateringStrategy:public WateringStrategy{
    
    
    
  virtual void water(Plant* plant);
  virtual void getWateringSchedule();

    
};


#endif