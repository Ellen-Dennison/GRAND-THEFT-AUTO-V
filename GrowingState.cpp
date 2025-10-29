#include "GrowingState.h"
#include "MatureState.h"

void GrowingState::grow() {
    if(plant->getAge() > 7 && plant->getHealth()>60){
        plant->setState(new MatureState());
        std::cout<<plant->getName()<<" transitioned to Mature State."<<std::endl;
    }
}

std::string GrowingState::getStateName(){
    return "Growing";
}

bool GrowingState::canBeSold(){
    return false;
}
