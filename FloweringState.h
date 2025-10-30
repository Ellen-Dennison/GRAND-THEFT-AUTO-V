#ifndef FLOWERINGSTATE_H
#define FLOWERINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class FloweringState : public PlantState
{
public:
    FloweringState();
    void grow();
    std::string getStateName() const override;
    bool canBeSold() const override;

};

#endif
