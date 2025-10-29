#include "FloweringState.h"

void FloweringState::grow() {
    //can't grow further. stays
}

std::string FloweringState::getStateName(){
    return "Flowering";
}

bool FloweringState::canBeSold(){
    return true;
}
