#include "WiltingState.h"
#include "DeadState.h"

void WiltingState::grow() {
    plant->adjustHealth(-5);
    std::cout<<plant->getName()<<" is wilting. Health declining..."<<std::endl;

    if(plant->getHealth() <=0){
        plant->setState(new DeadState());
        std::cout<<plant->getName()<<" has DIED."<<std::endl;
    }
}

std::string WiltingState::getStateName(){
    return "Wilting";
}

bool WiltingState::canBeSold(){
    return false;
}
