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
    std::vector<Plant*> greenhouse;

    /** @brief Collection of plants available on the sales floor. */
    std::vector<Plant*> salesFloor;

    /**
     * @brief Registry of plant factories organized by plant type and variety.
     * 
     * Nested map structure: outer key = plant type (Flower, Herb. Succulent, Tree)
     * inner key = plant Name ("Rose", "Basil", etc.), value = factory pointer
     * Used to create new plants through the Factory pattern.
     */
    std::map<std::string, std::map<std::string, PlantFactory*>> factories;

    /** @brief Caretaker responsible for managing plant mementos (state backups). */
    PlantCaretaker* careTaker;

    /** @brief Counter used to assign unique IDs to plants. */
    //int plantIdCounter; !This is used nowhere

    //FOR SALES TRACKING. this is for our 3 month summary

    /**
     * @brief holds total revenue collected over a quater
     */
    double totalRevenue;

    /**
     * @brief holds total customers served over a quater
     */
    int totalCustomers;

    /**
     * @brief holds total bundles sold over a quater
     */
    int bundleOrderCount;

    /**
     * @brief holds total singular plants sold over a quater
     */
    int individualOrderCount;

    /**
     * @brief holds total plants with decorative pots sold over a quater
     */
    int plantsWithPots;

    /**
     * @brief holds total plants with gift wrapping sold over a quater
     */
    int plantsWithGiftWrap;  

public:
    /**
     * @brief Constructs a new NurseryMediator.
     */
    NurseryMediator();

    /**
     * @brief Destroys the NurseryMediator and cleans up all dynamic memory.
     */
    ~NurseryMediator();

    /**
     * @brief Register a plant factory for a specific plant
     * @param plantType The general type (e.g., "Flower", "Herb", "Succulent", "Tree")
     * @param plantName The specific plant (e.g., "Rose", "Tulip", "Basil")
     * @param factory Pointer to the factory
     */
    void registerFactory(const std::string& plantType, const std::string& plantName, PlantFactory* factory);

    /**
     * @brief Create and add a new plant to the greenhouse using registered factory
     * @param plantType The general type
     * @param plantName The specific plant
     */
    void addNewPlant(const std::string& plantType, const std::string& plantName);

    /**
     * @brief Create multiple plants of the same variety
     * @param plantType The general type
     * @param plantName The specific plant
     * @param qty Number of plants to create
     */
    void addMultiplePlants(const std::string& plantType, const std::string& plantName, int qty);

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
     * @brief Processes a customer order using the orderBuilder
     * @param cusName The name of the customer placing the order.
     * @param plantType The type of plant requested.
     * @param wantsPot Whether the customer wants a decorative pot.
     * @param wantsWrapping Whether the customer wants gift wrapping.
     * @return A pointer to a newly created PlantOrder if successful, nullptr otherwise.
     */
    PlantOrder* processCustomerOrder(std::string cusName, std::string& plantType, bool wantsPot, bool wantsWrapping);

    /**
     * @brief Processes a bundle order for multiple plants of the same type using the OrderBuilder
     * @param cusName The name of the customer placing the order.
     * @param bundleName The name/title of the bundle (Flower or Bouquet or premium etc.)
     * @param plantType The type of plants to include in the bundle
     * @param discount The discount percentage to apply to the bundle
     * @param decorativePotOnFirst Whether to add a decorative pot to the whole bundle or to all plants in the bundle
     * @param giftWrapAll Whether to apply gift wrapping to all plants in the bundle
     * @return A pointer to a newly created PlantOrder if successful, nullptr otherwise
     */
    PlantOrder* processBundleOrder(const std::string& cusName, const std::string& bundleName, const std::string& plantType, double discount, bool decorativePotOnFirst, bool giftWrapAll);

    /**
     * @brief Simulates a customer browsing the sales floor.
     * @param customer Pointer to the Customer object browsing.
     */
    void customerBrowsingInteraction(Customer* customer);

    /**
     * @brief Displays a summary of the current nursery inventory (greenhouse and sales floor).
     */
    void displayInventory() const;

    /**
     * @brief Display only greenhouse plants
     */
    void displayGreenhouseInventory() const;

    /**
     * @brief Display only sales floor plants
     */
    void displaySalesFloorInventory() const;

    /**
     * @brief Display all registered factories
     */
    void displayRegisteredFactories() const;

    /**
     * @brief Get count of plants in greenhouse
     */
    int getGreenhouseCount() const;

    /**
     * @brief Get count of plants on sales floor
     */
    int getSalesFloorCount() const;

    /**
     * @brief Get count of specific plant type in a location
     * @param type The plant type to count
     * @param inGreenhouse true for greenhouse, false for sales floor
     */
    int getPlantCountByType(const std::string& type, bool inGreenhouse = true) const;

    /**
     * @brief Helper method to remove Plant from greenhouse
     * could be used once Plant is ready to be harvested
     * @param plant Pointer points to plant to be removed
     */
    bool removePlantFromGreenhouse(Plant* plant);

    /**
     * @brief Helper methods to remove Plant from salesFloor
     * could be used once Plant is sold or is revived and reverts to the growing state
     * @param plant Pointer points to plant to be removed
     */
    bool removePlantFromSalesFloor(Plant* plant);

    /**
     * @brief Returns a reference to the greenhouse plant collection.
     * @return Reference to the vector of greenhouse plants.
     */
    std::vector<Plant*>& getGreenhouse();

    /**
     * @brief Returns a reference to the sales floor plant collection.
     * @return Reference to the vector of sales floor plants.
     */
    std::vector<Plant*>& getSalesFloor();

    /**
     * @brief Gets a pointer to the plant caretaker
     * @return Pointer to the nursery's PlantCaretaker
     */
    PlantCaretaker* getCaretaker();

    //FOR SALES TRACIKING:
    /**
     * @brief Gets total revenue generated from all sales.
     * @return The total revenue in 
     */
    double getTotalRevenue() const { return totalRevenue; }
    
    /**
     * @brief Gets total number of customers served
     * @return The count of customers who completed purchases
     */
    int getTotalCustomers() const { return totalCustomers; }
    
    /**
     * @brief Gets number of bundle orders processed
     * @return The count of bundle orders
     */
    int getBundleOrderCount() const { return bundleOrderCount; }
    
    /**
     * @brief Gets number of individual plant orders processed
     * @return The count of individual plant orders
     */
    int getIndividualOrderCount() const { return individualOrderCount; }
    
    /**
     * @brief Gets number of plants sold with decorative pots
     * @return The count of plants that included decorative pots
     */
    int getPlantsWithPots() const { return plantsWithPots; }
    
    /**
     * @brief Gets number of plants sold with gift wrapping
     * @return The count of plants that included gift wrapping
     */
    int getPlantsWithGiftWrap() const { return plantsWithGiftWrap; }
    
    /**
     * @brief Display sales statistics for the reporting period
     */
    void displaySalesStatistics() const;
};

#endif // NURSERY_MEDIATOR_H

