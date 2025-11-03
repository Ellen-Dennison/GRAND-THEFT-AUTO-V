#ifndef WEEKLYWATERINGSTRATEGY_H
#define WEEKLYWATERINGSTRATEGY_H

#include<iostream>
#include<string>
#include "WateringStrategy.h"

class Plant;
/**
 * @brief Concrete watering strategy that waters plants once per week.
 * 
 * The WeeklyWateringStrategy class defines a watering behavior where
 * plants receive a fixed amount of water weekly, improving their health
 * by a set number of points.
 */

class WeeklyWateringStrategy : public WateringStrategy{
    public:
    /**
     * @brief Water plants accordingly. Daily each at 250ml, adding 5 health points
     * @param plant pointer to the plant object to be watered
     */
    void water(Plant* plant);

    /**
     * @brief Retrieves watering schedule for plant type
     * @return watering schedule in string form
    */  
    std::string getWateringSchedule() const;
};

#endif
