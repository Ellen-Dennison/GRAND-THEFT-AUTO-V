#ifndef WILTINGSTATE_H
#define WILTINGGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class WiltingState : public PlantState{
public:
    WiltingState();
    void grow();
    std::string getStateName() const override;
    bool canBeSold() const override;

};

#endif
