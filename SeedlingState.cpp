#include "SeedlingState.h"
#include "GrowingState.h"

void SeedlingState::grow() {
    if(plant->getAge() > 3){
        plant->setState(new GrowingState());
        std::cout<<plant->getName()<<" transitioned to Growing State."<<std::endl;
    }
}

std::string SeedlingState::getStateName(){
    return "Seedling";
}

bool SeedlingState::canBeSold(){
    return false;
}
