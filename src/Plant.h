#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <vector>
#include "Enums.h"
#include "WateringStrategy.h"
#include "PlantState.h"
#include "PlantMemento.h"
class PlantState;

/**
 * @brief Abstract class representing a general plant entitiy
 * 
 * The Plant class encapsulates attributes and behaviors common to all plants.
 * It defines interfaces for care operations (watering, sunlight, fertilizing),
 * growth management, and health tracking. It forms part of multiple design patterns
 */

class Plant{
protected:
    /**
     * @brief The plant's name
     */
    std::string name;

    /**
     * @brief The plant type(Flower, Succulent, Tree or Herb)
     */
    std::string type;

    /**
     * @brief How much the plant costs
     */
    double price;

    /**
     * @brief The plant's age measured in weeks
     */
    int age;

    /**
     * @brief The plant's health level from 0(dead) to 100(max health)
     */
    int healthLevel;

    /**
     * @brief Counter consecutive weeks without care
     */
    int neglectCounter;

    /**
     * @brief Indicates if a plant has been cared for this week
     */
    bool caredForThisWeek;

    /**
     * @brief Pointer to the current state in the plants' life cycle
     */
    PlantState* currState;

    /**
     * @brief Strategy for how the plant should be watered
     */
    WateringStrategy* wateringStrategy;

    /**
     * @brief Plant's Sunlight requirements
     */
    SunlightRequirement sunlightNeeds;

    /**
     * @brief Plant's Fertilizer requirements
     */
    FertilizerFrequency fertilizerNeeds;
    
    /** 
     * @brief Season in which the plant grows optimally
     * */
    GrowthSeason optimalSeason;

public:
    /**
     * @brief Constructs a new Plant object
     * @param n The name of the plant
     * @param t The type of the plant
     * @param p The price of the plant
     */
    Plant(std::string n, std::string t, double p);

    /**
     * @brief Copy constructor for deep copying plant data
     * @param other The plant to copy from
     */
    Plant(const Plant& other);  // Copy constructor

    /**
     * @brief Virtual destructor to ensure proper cleanup in derived classes
     */
    virtual ~Plant();

    /**
     * @brief Creates a deep copy of the current plant object
     * @return Pointer to the cloned plant
     */
    virtual Plant* clone() const = 0;

    /**
     * @brief Sets the current state of the plant
     */
    void setState(PlantState* state);

    /**
     * @brief sets the watering strategy used by this plant
     */
    void setWateringStrategy(WateringStrategy* strategy);

    /**
     * @brief Simulates plant growth for one cycle
     */
    void grow();

    /**
     * @brief Waters plant according to its set strategy
     */
    void water();

    /**
     * @brief Provide plant with required sunlight
     */
    void provideSunlight();

    /**
     * @brief Fertilizes plant based on it specific fertilizer needs
     */
    void fertilize();

    /**
     * @brief Adjusts plant health by specified amount
     * @param amount integer amount Plant health is adjusted by. Either positive or negative
     */
    void adjustHealth(int amount);

    /**
     * @brief increment neglect counter when plant is ignored
     */
    void incrementNeglect();

    /**
     * @brief reset neglect after care is provided for the week
     */
    void resetNeglect();

    /**
     * @brief Creates a memento capturing the current state of a plant
     * @return Pointer to a new PlantMemento object
     */
    PlantMemento* createMemento() const;

    /**
     * @brief Restores the plant's state from a saved memento
     * @param memento Pointer to the memento to restore from
     */
    void restoreFromMemento(PlantMemento* memento);

    /**
     * @brief Revives a withered plant from a memento snapshot
     * @param memento Pointer to the saved memento state
     */
    void revivePlant(PlantMemento* memento);

    /**
     * @brief getter
     * @return The plant's name
     */
    virtual std::string getName()const;

    /**
     * @brief getter
     * @return The type of plant
     */
    virtual std::string getType() const;

    /**
     * @brief getter
     * @return The price of the plant
     */
    virtual double getPrice() const;

    /**
     * @brief setter method to update the plant's price
     */
    virtual void setPrice(double p);

    /**
     * @brief getter
     * @return The age of the plant
     */
    int getAge() const;

    /**
     * @brief getter
     * @return The health level of the plant
     */
    int getHealth() const;

    /**
     * @brief getter
     * @return The current neglect counter
     */
    int getNeglectCounter() const;

    /**
     * @brief getter
     * @return The current state name of the plant
     */
    std::string getState() const;

    /**
     * @brief Check whether or not a plant is old and well enough to be sold
     * @return True if plant is healthy and old enough
     */
    bool isReadyForSale() const;

    /**
     * @brief getter
     * @return A description of the plant's watering schedule
     */
    std::string getWateringInfo() const;

    /**
     * @brief Checks if the plant is currently in its optimal growth season
     * @param currSeason The current season
     * @return True if in the optimal season
     */
    bool isInOptimalSeason(GrowthSeason currSeason) const;

    /**
     * @brief getter
     * @return a description of the plant’s sunlight needs
     */
    std::string getSunlightDescription() const;

    /**
     * @brief getter
     * @return a description of the plant’s fertilizer needs
     */
    std::string getFertilizerDescription() const;

    /**
     * @brief getter
     * @return a description of the plant’s optimal growth season
     */
    std::string getSeasonDescription() const;

    /**
     * @brief Displays information about the plant
     * This method should be implemented by derived classes 
     * to print customized information about the plant
     */
    virtual void display() const;

};

#endif
