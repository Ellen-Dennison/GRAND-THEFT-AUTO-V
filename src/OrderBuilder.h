#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include <iostream>
#include <string>
#include "PlantOrderh"
#include "PlantBundleh"
#include "PlantItemh"
#include "Planth"

/**
 * @class OrderBuilder
 * @brief Builder class for constructing PlantOrder objects with optional customizations
 * 
 * This class implements the Builder design pattern to construct complex PlantOrder objects
 * step by step It supports creating both individual plant orders and bundle orders with
 * optional decorations (decorative pots and gift wrapping)
 */
class OrderBuilder {
protected:
    /**
     * @brief The order being constructed
     */
    PlantOrder* order;

    /**
     * @brief Current bundle being built, nullptr if not building a bundle
     */
    PlantBundle* currentBundle;

    /**
     * @brief Tracks the current component being built
     */
    PlantComponent* currentComponent;
    
public:
    /**
     * @brief Constructor that initializes a new OrderBuilder
     */
    OrderBuilder();
    
    /**
     * @brief Destructor to cleann up resources if build was not called
     */
    virtual ~OrderBuilder();
    
    /**
     * @brief Sets the customer name for the order
     * @param name The customer's name
     * @return Pointer to this OrderBuilder
     */
    OrderBuilder* setCustomer(std::string name);
    
    /**
     * @brief Sets a single plant for the order with optional decorations
     * @param plant Pointer to the plant to be ordered
     * @param decorativePot Whether to add a decorative pot
     * @param giftWrap Whether to add gift wrapping
     * @return Pointer to this OrderBuilder
     */
    OrderBuilder* setPlant(Plant* plant, bool decorativePot = false, bool giftWrap = false);
    
    /**
     * @brief Starts building a bundle order with multiple plants
     * @param bundleName The name/title of the bundle
     * @param discount The discount percentage to apply
     * @return Pointer to this OrderBuilder
     */
    OrderBuilder* startBundle(std::string bundleName, double discount);
    
    /**
     * @brief Adds a plant to the current bundle being built
     * @param plant Pointer to the plant to add to the bundle
     * @param decorativePot Whether to add a decorative pot to this plant
     * @param giftWrap Whether to add gift wrapping to this plant
     * @return Pointer to this OrderBuilder
     */
    OrderBuilder* addPlantToBundle(Plant* plant, bool decorativePot = false, bool giftWrap = false);
    
    /**
     * @brief Finishes building the current bundle and adds it to the order
     * @return Pointer to this OrderBuilder
     */
    OrderBuilder* finishBundle();
    
    /**
     * @brief Builds and returns the final PlantOrder
     * @return Pointer to the constructed PlantOrder, or nullptr if construction failed
     * @note After calling build(), the builder's internal order is set to nullptr
     */
    PlantOrder* build();
    
    /**
     * @brief Checks if currently building a bundle
     * @return True if a bundle is being constructed, false otherwise
     */
    bool isBuildingBundle() const;
    
    /**
     * @brief Resets the builder to its initial state. Partial construction is cleared as well
     */
    void reset();
};

#endif
