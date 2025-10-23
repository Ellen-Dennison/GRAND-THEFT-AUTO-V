#ifndef BIWEEKLYWATERINGSTRATEGY_H
#define BIWEEKLYWATERINGSTRATEGY_H

#include<iostream>
#include<string>
#include "WateringStrategy.h"

class Plant;

class BiWeeklyWateringStrategy : public WateringStrategy{
    public:
    void water(Plant* plant);
    std::string getWateringSchedule() const;
};

#endif
