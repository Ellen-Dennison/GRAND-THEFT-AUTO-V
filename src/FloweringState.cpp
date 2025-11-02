#include "FloweringState.h"

FloweringState::FloweringState()
{}

void FloweringState::grow() 
{
    //can't grow further. stays
}

std::string FloweringState::getStateName() const
{
    return "Flowering";
}

bool FloweringState::canBeSold() const
{
    return true;
}
