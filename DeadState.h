#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class DeadState : public PlantState{
public:
    void grow();
    std::string getStateName();
    bool canBeSold();

};

#endif
