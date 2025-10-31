/**
 * @file PlantOrder.h
 * @brief Defines the PlantOrder class representing a customer's plant purchase order.
 *
 * The `PlantOrder` class encapsulates all the details of a customer's order,
 * including the selected plant, optional customizations (gift wrapping, decorative pot),
 * and the customer’s name. 
 * 
 * This class is primarily used by the `NurseryMediator` and `OrderBuilder`
 * to create, manage, and display order information in the nursery management system.
 */

#ifndef PLANTORDER_H
#define PLANTORDER_H

#include <string>
#include "Plant.h"

using namespace std;

/**
 * @class PlantOrder
 * @brief Represents a customer's plant purchase order.
 *
 * The `PlantOrder` class stores details about a specific plant order,
 * such as which plant is being purchased, who the customer is, 
 * and any additional options the customer selected (e.g., decorative pot or gift wrapping).
 *
 * ### Example:
 * ```cpp
 * PlantOrder order;
 * order.customerName = "Alice Green";
 * order.plant = new Flower("Rose", "Flower", 45.0);
 * order.hasGiftWrapping = true;
 * order.hasDecorativePot = false;
 * 
 * order.display();
 * ```
 */
class PlantOrder {
public:
    /** @brief Pointer to the plant being purchased. */
    Plant* plant;

    /** @brief Indicates whether the customer requested gift wrapping. */
    bool hasGiftWrapping;

    /** @brief The name of the customer placing the order. */
    string customerName;

    /** @brief Indicates whether the customer requested a decorative pot. */
    bool hasDecorativePot;

    /**
     * @brief Default constructor initializing an empty plant order.
     */
    PlantOrder();

    /**
     * @brief Displays the details of the order to the console.
     *
     * Prints out the customer's name, plant type, and optional features.
     */
    void display();
};

#endif // PLANTORDER_H
