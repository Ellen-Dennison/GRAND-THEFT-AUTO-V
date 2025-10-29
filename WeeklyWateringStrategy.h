#ifndef WEEKLYWATERINGSTRATEGY_H
#define WEEKLYWATERINGSTRATEGY_H

#include<iostream>
#include<string>
#include "WateringStrategy.h"

class Plant;

class WeeklyWateringStrategy : public WateringStrategy{
    public:
    void water(Plant* plant);
    std::string getWateringSchedule() const;
};

#endif
