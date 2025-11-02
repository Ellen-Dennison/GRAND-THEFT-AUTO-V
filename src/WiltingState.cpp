#include "WiltingState.h"
#include "DeadState.h"
#include "Plant.h"

WiltingState::WiltingState() : PlantState() {
}

void WiltingState::grow() {
    plant->adjustHealth(-5);
    std::cout<<plant->getName()<<" is wilting. Health declining..."<<std::endl;

    if(plant->getHealth() <=0){
        std::string plantName = plant->getName();
        plant->setState(new DeadState());
        std::cout<<plantName<<" has DIED."<<std::endl;
    }
}

std::string WiltingState::getStateName() const{
    return "Wilting";
}

bool WiltingState::canBeSold() const{
    return false;
}
