#include "DeadState.h"

void DeadState::grow() {
    //Dead can't grow
}

std::string DeadState::getStateName(){
    return "Dead";
}

bool DeadState::canBeSold(){
    return false;
}
