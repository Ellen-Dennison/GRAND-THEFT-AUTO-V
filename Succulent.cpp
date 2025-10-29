#include "Succulent.h"
//#include "WeeklyWateringStrategy.h"
#include <iostream>

Succulent::Succulent(std::string name, double price) 
    : Plant(name, "Succulent", price) {
   /*  sunlightNeeds = FULL_SUN;
    fertilizerNeeds = SEASONAL_FERTILIZER;
    optimalSeason = SUMMER;
    setWateringStrategy(new WeeklyWateringStrategy()); */
}

Plant* Succulent::clone() const {
    return new Succulent(*this);
}
