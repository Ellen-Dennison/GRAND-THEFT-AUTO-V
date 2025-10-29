#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <iostream>
#include <string>

class Plant;

class PlantState{
protected:
    Plant* plant;

public:
    virtual ~PlantState(){};
    void setPlant(Plant* p);
    virtual void grow() = 0;
    virtual std::string getStateName() const = 0;
    virtual bool canBeSold() const = 0;
};

#endif
