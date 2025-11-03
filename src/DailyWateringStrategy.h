#ifndef DAILYWATERINGSTRATEGY_H
#define DAILYWATERINGSTRATEGY_H

#include<iostream>
#include<string>

#include "WateringStrategy.h"

class Plant;

/**
 * @brief Concrete watering strategy that waters plants Daily
 * 
 * The DailyWateringStrategy class defines a watering behavior where
 * plants receive a fixed amount of water daily, improving their health
 * by a set number of points.
 */

class DailyWateringStrategy : public WateringStrategy{
    public:
    /**
     * @brief Water plants accordingly. Daily each at 500ml, adding 15 health points
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
