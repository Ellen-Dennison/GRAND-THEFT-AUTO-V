#include "SeedlingState.h"
#include "GrowingState.h"
#include "Plant.h"

SeedlingState::SeedlingState() : PlantState() {
}

void SeedlingState::grow() {
    if(plant->getAge() > 3){
        std::string plantName = plant->getName();
        plant->setState(new GrowingState());
        std::cout << plantName << " transitioned to Growing State." << std::endl;
    }
}

std::string SeedlingState::getStateName() const{
    return "Seedling";
}

bool SeedlingState::canBeSold() const{
    return false;
}
