#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <iostream>
#include <string>

class Plant;

/**
 * @brief Abstract base class representing the state of a plant.
 * 
 * The PlantState class defines the interface for various growth stages
 * of a plant. From Seedling -> Growing -> Mature -> Flowering -> Wilting ->Dead. 
 * Each state determines how the plant behaves, grows, and whether it can be sold.
 * 
 * This class is part of the State design pattern, where a Plant object changes its internal behavior depending on its current state.
 */

class PlantState{
protected:
    /**
     * @brief Pointer to the plant associated with this state
     */
    Plant* plant;

public:
    /**
     * @brief Default constructor
     */
    PlantState();

    /**
     * @brief Virtual destructor for cleanup of derived states
     */
    virtual ~PlantState() {}

    /**
     * @brief Assigns the plant associated with this state
     * @param p Pointer to the Plant object that owns this state
     */
    void setPlant(Plant* p);

    /**
     * @brief Defines how the plant grows in this state.
     * Concrete subclasses implement how growth affects the plant's attributes
     */
    virtual void grow() = 0;

    /**
     * @brief Retrieves the name of the current state
     * @return A string representing the name of this plant state
     */
    virtual std::string getStateName() const = 0;

    /**
     * @brief Determines whether the plant can be sold in this state
     * @return True if the plant is past 7 weeks, false otherwise
     */
    virtual bool canBeSold() const = 0;
};

#endif
