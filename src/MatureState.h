#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the mature state of a plant.
 * The MatureState class defines behavior for a fully grown plant.
 * In this state, the plant can be sold and grows into the flowering state if it grows further.
 */
class MatureState : public PlantState {
public:
    /**
     * @brief Constructs a new MatureState object.
     */
    MatureState() {};

    /**
     * @brief Handles growth logic for the mature state.
     * Grows a plant further into the flowering state once it reaches age >12
     * Handles state transitions
     */
    void grow() override;

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Mature"
     */
    std::string getStateName() const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return True as plants are of age in this state
     */
    bool canBeSold() const override;

};

#endif
