#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

class SeedlingState : public PlantState{
public:
    SeedlingState();
    void grow();
    std::string getStateName() const override;
    bool canBeSold() const override;
   

};

#endif
