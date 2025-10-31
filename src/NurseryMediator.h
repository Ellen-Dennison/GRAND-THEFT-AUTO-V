/**
 * @file NurseryMediator.h
 * @brief Defines the NurseryMediator class, which coordinates interactions 
 *        between plants, customers, and factories in the plant nursery system.
 *
 * The NurseryMediator acts as a central controller in the system.
 * It manages plant creation, care routines, customer orders, 
 * and the transition of plants from greenhouse to sales floor.
 */

#ifndef NURSERY_MEDIATOR_H
#define NURSERY_MEDIATOR_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Plant.h"
#include "PlantFactory.h"
#include "PlantCaretaker.h"
#include "Customer.h"
#include "PlantOrder.h"
#include "FlowerFactory.h"
#include "SucculentFactory.h"
#include "TreeFactory.h"
#include "HerbFactory.h"

using namespace std;

/**
 * @class NurseryMediator
 * @brief Mediator that manages communication between different components
 *        of the nursery system (plants, factories, customers, and caretaker).
 *
 * Responsibilities include:
 * - Creating new plants through factories
 * - Managing plant lifecycle (growth, care, sale readiness)
 * - Handling customer interactions and orders
 * - Saving and restoring plant states (Memento pattern)
 * - Monitoring plant health and progress
 */
class NurseryMediator {
private:
    /** @brief Collection of plants currently in the greenhouse (growing stage). */
    vector<Plant*> greenhouse;

    /** @brief Collection of plants available on the sales floor. */
    vector<Plant*> salesFloor;

    /** @brief Map linking plant type names to their corresponding factory objects. */
    map<string, PlantFactory*> factories;

    /** @brief Caretaker responsible for managing plant mementos (state backups). */
    PlantCaretaker* careTaker;

    /** @brief Counter used to assign unique IDs to plants. */
    int plantIdCounter;

public:
    /**
     * @brief Constructs a new NurseryMediator and initializes plant factories.
     */
    NurseryMediator();

    /**
     * @brief Destroys the NurseryMediator and cleans up all dynamic memory.
     */
    ~NurseryMediator();

    /**
     * @brief Adds a new plant of the given type to the greenhouse.
     * @param plantType The string name of the plant type (e.g., "Flower", "Tree").
     */
    void addNewPlant(string plantType);

    /**
     * @brief Performs care routines on all greenhouse plants (watering, sunlight, fertilizing).
     */
    void careForGreenhouse();

    /**
     * @brief Advances time in the greenhouse, simulating plant growth.
     * @param weeks The number of weeks to advance.
     */
    void advanceTime(int weeks);

    /**
     * @brief Moves mature plants from the greenhouse to the sales floor.
     */
    void harvestMaturePlants();

    /**
     * @brief Saves the state (memento) of all healthy plants for potential restoration.
     */
    void saveHealthyStates();

    /**
     * @brief Checks for plants that are wilting or unhealthy.
     */
    void checkForWiltingPlants();

    /**
     * @brief Processes a customer order by assigning a plant from the sales floor.
     * 
     * @param cusName The name of the customer placing the order.
     * @param plantType The type of plant requested.
     * @param wantsPot Whether the customer wants a decorative pot.
     * @param wantsWrapping Whether the customer wants gift wrapping.
     * @return A pointer to a newly created PlantOrder if successful, nullptr otherwise.
     */
    PlantOrder* processCustomerOrder(string cusName, string plantType, bool wantsPot, bool wantsWrapping);

    /**
     * @brief Simulates a customer browsing the sales floor.
     * @param customer Pointer to the Customer object browsing.
     */
    void customerBrowsingInteraction(Customer* customer);

    /**
     * @brief Displays a summary of the current nursery inventory (greenhouse and sales floor).
     */
    void displayInventory();

    /**
     * @brief Returns a reference to the greenhouse plant collection.
     * @return Reference to the vector of greenhouse plants.
     */
    vector<Plant*>& getGreenhouse();

    /**
     * @brief Returns a reference to the sales floor plant collection.
     * @return Reference to the vector of sales floor plants.
     */
    vector<Plant*>& getSalesFloor();
};

#endif // NURSERY_MEDIATOR_H

