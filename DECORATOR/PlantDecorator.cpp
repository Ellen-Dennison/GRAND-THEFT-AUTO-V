#include "PlantDecorator.h"

PlantDecorator::~PlantDecorator()
{}

std::string PlantDecorator::getName()
{ return wrappedPlant->getName(); }


std::string PlantDecorator::getType()
{ return wrappedPlant->getType(); }
