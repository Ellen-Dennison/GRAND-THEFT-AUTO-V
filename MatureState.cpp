#include "MatureState.h"
#include "FloweringState.h"

void MatureState::grow() {
    if(plant->getAge() > 12){
        plant->setState(new FloweringState());
        std::cout<<plant->getName()<<" transitioned to Flowering State."<<std::endl;
    }
}

std::string MatureState::getStateName(){
    return "Mature";
}

bool MatureState::canBeSold(){
    return true;
}
