#ifndef DAILYWATERINGSTRATEGY_H
#define DAILYWATERINGSTRATEGY_H

#include "WateringStrategy.h"

#include "Plant.h"

using namespace std;

class DailyWateringStrategy:public WateringStrategy{
    
    
    
  virtual void water(Plant* plant);
  virtual void getWateringSchedule();

    
};


#endif