#include "PlantState.h"
#include "Plant.h"
#include <iostream>

PlantState::PlantState() : plant(nullptr) {
}

void PlantState::setPlant(Plant* p) {
    this->plant = p;
}
