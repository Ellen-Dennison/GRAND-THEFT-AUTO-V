#ifndef WILTINGSTATE_H
#define WILTINGGSTATE_H

#include "PlantState.h"
#include <iostream>
#include <string>

/**
 * @brief Represents the Wilting state of a plant
 * The WiltingState class defines behavior for a plant that has been
 * neglected long enough to reach poor health level conditions
 * In this state, the plant cannot be sold as it is dying
 */
class WiltingState : public PlantState{
public:
    /**
     * @brief Constructs a new WiltingState object
     */
    WiltingState();

    /**
     * @brief Handles growth logic for the wilting state
     * Plant does not grow any further although it can be revived as long as the plants's health remains >0
     * A plant enters this state once it reaches a health level <40
     * Plant starts declining at 5 health levels as it s wilting
     */
    void grow() override;

    /**
     * @brief Returns the name of this state
     * @return A string representing the state name - "Wilting"
     */   
    std::string getStateName() const override;

    /**
     * @brief Indicates whether the plant can be sold
     * @return false. Plant is dying
     */
    bool canBeSold() const override;

};

#endif
