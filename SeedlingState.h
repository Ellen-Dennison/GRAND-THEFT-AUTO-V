#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class SeedlingState : public PlantState{
public:
    void grow();
    std::string getStateName();
    bool canBeSold();

};

#endif
