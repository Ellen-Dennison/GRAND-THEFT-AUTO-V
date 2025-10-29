#include "MatureState.h"
#include "FloweringState.h"
#include "Plant.h"

MatureState::MatureState() : PlantState() {
}

void MatureState::grow() {
    if(plant->getAge() > 12){
        std::string plantName = plant->getName();
        plant->setState(new FloweringState());
        std::cout<<plantName<<" transitioned to Flowering State."<<std::endl;
    }
}

std::string MatureState::getStateName()const{
    return "Mature";
}

bool MatureState::canBeSold()const{
    return true;
}
