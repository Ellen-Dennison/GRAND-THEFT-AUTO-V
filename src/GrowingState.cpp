#include "GrowingState.h"
#include "MatureState.h"
#include "Plant.h"

GrowingState::GrowingState()
{}

void GrowingState::grow() {
    if(plant->getAge() > 7 && plant->getHealth() > 60){
        std::string plantName = plant->getName(); //get name first
        plant->setState(new MatureState());
        std::cout << plantName << " transitioned to Mature State." << std::endl;
    }
}

std::string GrowingState::getStateName() const{
    return "Growing";
}

bool GrowingState::canBeSold() const{
    return false;
}
