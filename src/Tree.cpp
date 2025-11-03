#include "Tree.h"
#include "WeeklyWateringStrategy.h"
#include <iostream>

Tree::Tree(std::string name, double price) : Plant(name, "Tree", price) {
    sunlightNeeds = FULL_SUN;
    fertilizerNeeds = SEASONAL_FERTILIZER;
    optimalSeason = ALL_SEASONS;
    setWateringStrategy(new WeeklyWateringStrategy());
}

Plant* Tree::clone() const {
    return new Tree(*this);
}
