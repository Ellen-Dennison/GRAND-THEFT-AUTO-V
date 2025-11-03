#include "PlantDecorator.h"
#include <iostream>

PlantDecorator::PlantDecorator(Plant* p) 
    : Plant(p->getName(), p->getType(), p->getPrice()) {
    wrappedPlant = p;
}

PlantDecorator::~PlantDecorator() {
    delete wrappedPlant;
}

std::string PlantDecorator::getName() const {
    return wrappedPlant->getName();
}

std::string PlantDecorator::getType() const {
    return wrappedPlant->getType();
}

double PlantDecorator::getPrice() const {
    return wrappedPlant->getPrice();
}

void PlantDecorator::display() const {
    wrappedPlant->display();
}
