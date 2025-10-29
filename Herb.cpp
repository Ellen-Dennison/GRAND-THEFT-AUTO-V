#include "Herb.h"
//#include "BiWeeklyWateringStrategy.h"
#include <iostream>

Herb::Herb(std::string name, double price) 
    : Plant(name, "Herb", price) {
    /* sunlightNeeds = FULL_SUN;
    fertilizerNeeds = MONTHLY_FERTILIZER;
    optimalSeason = SUMMER;
    setWateringStrategy(new BiWeeklyWateringStrategy()); */
}

Plant* Herb::clone() const {
    return new Herb(*this);
}
