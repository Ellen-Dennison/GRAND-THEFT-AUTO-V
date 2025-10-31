/**
 * @file OrderBuilder.h
 * @brief Defines the OrderBuilder class used to construct customized PlantOrder objects.
 *
 * The `OrderBuilder` class implements the Builder design pattern for 
 * creating `PlantOrder` instances in a flexible and readable manner.
 * 
 * It allows chaining of configuration methods such as setting the customer name,
 * selecting a plant, and adding optional customizations like gift wrapping or
 * decorative pots.
 */

#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include <iostream>
#include <string>
#include "PlantOrder.h"

using namespace std;

/**
 * @class OrderBuilder
 * @brief A builder class for constructing complex `PlantOrder` objects step-by-step.
 *
 * This class helps in building a `PlantOrder` by setting its properties through 
 * method chaining. Each method modifies the internal `PlantOrder` being built
 * and returns a pointer to the same builder object.
 *
 * ### Example:
 * ```cpp
 * OrderBuilder builder;
 * PlantOrder* order = builder
 *     .setCustomer("Alice")
 *     .setplant(flowerPlant)
 *     .addGiftWrapping()
 *     .addDecorativePot()
 *     .build();
 * 
 * order->display();
 * delete order;
 * ```
 */
class OrderBuilder {
protected:
    /** @brief Pointer to the `PlantOrder` object being built. */
    PlantOrder* order;

public:
    /**
     * @brief Default constructor initializes a new `PlantOrder` instance.
     */
    OrderBuilder();

    /**
     * @brief Destructor to clean up allocated resources if needed.
     */
    ~OrderBuilder();

    /**
     * @brief Sets the customer's name for the order.
     * @param name The name of the customer placing the order.
     * @return A pointer to the current `OrderBuilder` (for method chaining).
     */
    OrderBuilder* setCustomer(string name);

    /**
     * @brief Sets the plant associated with this order.
     * @param plant Pointer to the `Plant` being ordered.
     * @return A pointer to the current `OrderBuilder` (for method chaining).
     */
    OrderBuilder* setplant(Plant* plant);

    /**
     * @brief Adds a decorative pot customization to the order.
     * @return A pointer to the current `OrderBuilder` (for method chaining).
     */
    OrderBuilder* addDecorativePot();

    /**
     * @brief Adds gift wrapping to the order.
     * @return A pointer to the current `OrderBuilder` (for method chaining).
     */
    OrderBuilder* addGiftWrapping();

    /**
     * @brief Finalizes and returns the constructed `PlantOrder`.
     * 
     * Once `build()` is called, the `PlantOrder` is considered ready for use.
     * The caller is responsible for deleting the returned pointer.
     *
     * @return A pointer to the fully built `PlantOrder` object.
     */
    PlantOrder* build();
};

#endif // ORDERBUILDER_H
