#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class MatureState : public PlantState{
public:
    MatureState() {};
    void grow();
    std::string getStateName() const override;
    bool canBeSold() const override;

};

#endif
