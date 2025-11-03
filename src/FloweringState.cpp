#include "FloweringState.h"

FloweringState::FloweringState() : PlantState() {
}

void FloweringState::grow() {
    //can't grow further. stays
}

std::string FloweringState::getStateName() const{
    return "Flowering";
}

bool FloweringState::canBeSold() const{
    return true;
}
