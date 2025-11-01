/**
 * @file PlantMemento.h
 * @brief Memento class for storing plant state snapshots
 *
 * This class implements the Memento pattern to save and restore plant states.
 * The snapshot contains the plant's important attributes like the state name, age and health level.
 *
 * Design Pattern: Memento (Memento participant)
 * Related Classes: PlantCaretaker (Caretaker), Plant (Originator)
 */

#ifndef PLANTMEMENTO_H
#define PLANTMEMENTO_H


#include <string>

/**
 * @class PlantMemento
 * @brief Stores a snapshot of a Plant's state for later restoration
 */
class PlantMemento{
private:

    std::string stateName;
    int age;
    int healthLevel;

public:
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

    PlantMemento(const std::string& state, int age, int health);

    /**
     * @brief Destructor for PlantMemento
     *
     * Default destructor to clean up memento resources.
     */
    ~PlantMemento();

    /**
     * @brief Gets the stored state name
     *
     * @return The state name as a string
     */
    std::string getState() const;

    /**
     * @brief Gets the stored age
     *
     * @return The plant's age in weeks at the time of snapshot
     */
    int getAge() const;

    /**
     * @brief Gets the stored health level
     *
     * @return The plant's health level at the time of snapshot
     */
    int getHealth() const;


    /**
     * @brief Displays the memento information
     */
    void display() const;




};
#endif
