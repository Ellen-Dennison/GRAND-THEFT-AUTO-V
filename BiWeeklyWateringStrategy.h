#ifndef BIWEEKLYWATERINGSTRATEGY_H
#define BIWEEKLYWATERINGSTRATEGY_H

#include "WateringStrategy.h"

#include "Plant.h"

using namespace std;

class BiWeeklyWateringStrategy:public WateringStrategy{
    
    
    
  virtual void water(Plant* plant);
  virtual void getWateringSchedule();

    
};


#endif