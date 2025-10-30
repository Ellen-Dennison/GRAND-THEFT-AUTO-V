#include "DailyWateringStrategy.h"
#include "Plant.h"
#include <iostream>

void DailyWateringStrategy::water(Plant* plant){
    plant->adjustHealth(15);
    std::cout<<"Daily watering applied (500ml)\n"
            <<"Health +15" <<std::endl;

}

std::string DailyWateringStrategy::getWateringSchedule() const{
    return "Daily watering: 500ml per day";
}
