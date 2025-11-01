#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the Seedling state of a plant
 * The SeedlingState class defines behavior for a plant that has just been planted.
 * In this state, the plant cannot be sold. It is in its early stages of growing
 */
class SeedlingState : public PlantState{
public:
    /**
     * @brief Constructs a new SeedlingState object
     */
    SeedlingState();

    /**
     * @brief Handles growth logic for the seedling state
     * Plant grows and transitions into GrowingState
     * This happens once it reaches an age > 3
     */
    void grow() override;

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Seedling"
     */       
    std::string getStateName() const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return false. Plant is only a seed in this state
     */
    bool canBeSold() const override;

};

#endif
