#ifndef FLOWERINGSTATE_H
#define FLOWERINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the Flowering state of a plant
 * The FloweringState class defines behavior for a fully grown beautiful and wild plant.
 * In this state, the plant can be sold and grows no further.
 */
class FloweringState : public PlantState{
public:
    /**
     * @brief Constructs a new FloweringState object
     */
    FloweringState();

    /**
     * @brief Handles growth logic for the flowering state
     * Plant does not grow any further
     */
    void grow();

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Flowering"
     */
    std::string getStateName() const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return true. Plants are of age and ready to attract customers
     */
    bool canBeSold() const override;

};

#endif
