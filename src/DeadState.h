#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the Dead state of a plant
 * The DeadState class defines behavior for a plant that has been neglected to the point of no return.
 * In this state, the plant can neither be sold nor revived
 */
class DeadState : public PlantState{
public:
    /**
     * @brief Constructs a new DeadState object
     */
    DeadState() {};

    /**
     * @brief Handles growth logic for the dead state
     * Plant does not grow any further or can be revived
     */
    void grow();

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Dead"
     */
    std::string getStateName() const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return false. Plant is long gone
     */
    bool canBeSold() const override;

};

#endif
