/**
 * @file PlantMemento.cpp
 * @brief Implementation of the PlantMemento class
 *
 * This class implements the Memento pattern to save and restore plant states.
 * The snapshot contains the plant's important attributes like the state name, age and health level.
 */
#include "PlantMemento.h"
#include <iostream>

/**
 * @brief Constructs a PlantMemento with the given plant state
 * Creates a snapshot of a Plant's state and the constructor is called by the Plant class when creating a Memento.
 *
 * @param state The name of the plant's current state
 * @param age The current age of the plant in weeks
 * @param health The current health level of the
 *
 * @pre health should be between 0 and 100
 * @pre plantAge should be non-negative
 */
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

/**
 * @brief Destructor for PlantMemento
 *
 * Default destructor to clean up memento resources.
 */
PlantMemento::~PlantMemento() {

}

/**
 * @brief Gets the stored state name
 *
 * @return The state name as a string
 */
std::string PlantMemento::getState() const {
    return stateName;
}

/**
 * @brief Gets the stored age
 *
 * @return The plant's age in weeks at the time of snapshot
 */
int PlantMemento::getAge() const {
    return age;
}


/**
 * @brief Gets the stored health level
 *
 * @return The plant's health level at the time of snapshot
 */
int PlantMemento::getHealth() const {
    return healthLevel;
}


/**
 * @brief Displays the memento information
 */
void PlantMemento::display() const {
    std::cout << "------ Plant Memento ------" << std::endl;
    std::cout << "State: " << stateName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Health: " << healthLevel << "%" << std::endl;
    std::cout << "--------------------------" << std::endl;
}
