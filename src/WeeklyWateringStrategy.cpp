#include "WeeklyWateringStrategy.h"
#include "Plant.h"
#include <iostream>

void WeeklyWateringStrategy::water(Plant* plant){
    plant->adjustHealth(5);
    std::cout<<"Weekly watering applied (250ml)\n"
             <<"Health +5" <<std::endl;

}

std::string WeeklyWateringStrategy::getWateringSchedule() const{
    return "Weekly watering: 250ml per week";
}
