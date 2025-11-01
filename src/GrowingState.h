#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the Growing state of a plant.
 * The GrowingState class defines behavior for a fully grown plant.
 * In this state, the plant cannot be sold and grows into the Mature state if it grows further.
 */
class GrowingState : public PlantState{
public:
    /**
     * @brief Constructs a new GrowingState object
     */
    GrowingState();

    /**
     * @brief Handles growth logic for the growing state
     * Grows a plant further into the Mature state once it reaches age >7 and health >60
     * Handles state transitions
     */
    void grow();

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Growing"
     */
    std::string getStateName()const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return false as plant are not of age to be sold on this state
     */
    bool canBeSold() const override;

};

#endif
