#include "BiWeeklyWateringStrategy.h"
#include "Plant.h"
#include <iostream>

void BiWeeklyWateringStrategy::water(Plant* plant){
    plant->adjustHealth(10);
    std::cout<<"Bi-weekly watering applied (350ml)\n"
             <<"Health +10" <<std::endl;

}

std::string BiWeeklyWateringStrategy::getWateringSchedule() const{
    return "Bi-weekly watering: 350ml twice a week";
}
