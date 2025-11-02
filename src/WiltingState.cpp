#include "WiltingState.h"
#include "DeadState.h"


WiltingState::WiltingState()
{}



void WiltingState::grow() 
{
    plant->adjustHealth(-5);
    std::cout<<plant->getName()<<" is wilting. Health declining..."<<std::endl;

    if(plant->getHealth() <=0)
    {
        std::cout<<plant->getName()<<" has DIED."<<std::endl;
        plant->setState(new DeadState);
        
    }
}

std::string WiltingState::getStateName() const
{
    return "Wilting";
}

bool WiltingState::canBeSold() const
{
    return false;
}
