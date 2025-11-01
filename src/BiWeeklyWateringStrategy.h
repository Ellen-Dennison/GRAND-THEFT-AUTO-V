#ifndef BIWEEKLYWATERINGSTRATEGY_H
#define BIWEEKLYWATERINGSTRATEGY_H

#include<iostream>
#include<string>
#include "WateringStrategy.h"

class Plant;
/**
 * @brief Concrete watering strategy that waters plants twice per week.
 * 
 * The BiWeeklyWateringStrategy class defines a watering behavior where
 * plants receive a fixed amount of water weekly, improving their health
 * by a set number of points.
 */

class BiWeeklyWateringStrategy : public WateringStrategy{
    public:
    /**
     * @brief Water plants accordingly. Twice a week each at 350ml, adding 10 health points
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
