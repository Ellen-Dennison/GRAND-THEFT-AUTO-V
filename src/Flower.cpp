#include "Flower.h"
#include "DailyWateringStrategy.h"
#include <iostream>

Flower::Flower(std::string name, double price) 
    : Plant(name, "Flower", price) {
    sunlightNeeds = FULL_SUN;
    fertilizerNeeds = WEEKLY_FERTILIZER;
    optimalSeason = SPRING;
    setWateringStrategy(new DailyWateringStrategy());
}

Plant* Flower::clone() const {
    return new Flower(*this);
}
