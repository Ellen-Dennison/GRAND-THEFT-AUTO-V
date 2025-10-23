#ifndef DAILYWATERINGSTRATEGY_H
#define DAILYWATERINGSTRATEGY_H

#include<iostream>
#include<string>

#include "WateringStrategy.h"

class Plant;

class DailyWateringStrategy : public WateringStrategy{
    public:
    void water(Plant* plant);
    std::string getWateringSchedule() const;
};

#endif
