#ifndef WILTINGSTATE_H
#define WILTINGGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class WiltingState : public PlantState{
public:
    void grow();
    std::string getStateName();
    bool canBeSold();

};

#endif
