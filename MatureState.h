#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class MatureState : public PlantState{
public:
    void grow();
    std::string getStateName();
    bool canBeSold();

};

#endif
