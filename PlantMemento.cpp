
#include "PlantMemento.h"
#include <iostream>

PlantMemento::PlantMemento(const std::string &state, int age, int health): stateName(state), age(age), healthLevel(health) {
    if (healthLevel < 0) {
        healthLevel =0;
    } else if (healthLevel > 100) {
        healthLevel = 100;
    }

    if (age < 0) {
        age =0;
    }
}

PlantMemento::~PlantMemento() {

}

std::string PlantMemento::getStateName() const {
    return stateName;
}

int PlantMemento::getAge() const {
    return age;
}

int PlantMemento::getHealthLevel() const {
    return healthLevel;
}

void PlantMemento::display() const {
    std::cout << "------ Plant Memento ------" << std::endl;
    std::cout << "State: " << stateName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Health: " << healthLevel << "%" << std::endl;
    std::cout << "--------------------------" << std::endl;
}