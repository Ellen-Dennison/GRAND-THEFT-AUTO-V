#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class DeadState : public PlantState{
public:
    void grow() override;
    std::string getStateName() const override;
    bool canBeSold() const override;

};

#endif
