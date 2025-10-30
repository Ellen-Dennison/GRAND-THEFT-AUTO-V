#include "DeadState.h"

void DeadState::grow() {
    //Dead can't grow
}

std::string DeadState::getStateName() const
{
    return "Dead";
}

bool DeadState::canBeSold() const
{
    return false;
}
