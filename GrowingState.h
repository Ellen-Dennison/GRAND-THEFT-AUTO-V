#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class GrowingState : public PlantState{
public:
    void grow();
    std::string getStateName() const override;
    bool canBeSold() const override;

};

#endif
