#ifndef PLANTORDER_H
#define PLANTORDER_H

#include <string>
#include "PlantComponent.h"

/**
 * @class PlantOrder
 * @brief Represents a customer's plant order containing customer information and plant components.
 * 
 * The PlantOrder class manages a single order for a customer, which can contain
 * individual plant items, bundles, or decorated versions of plants. It handles
 * the association between a customer and their selected plant components.
 */
class PlantOrder {
private:
    /**
     * @brief Name of customer placing order
     */
    std::string customerName;

    /**
     * @brief Pointer to plant component
     * @note can be PlantItem, PlantBundle, or decorated versions
     */
    PlantComponent* plantComponent;

public:
    /**
     * @brief Default constructor for PlantOrder
     * Initializes a new plant order with empty customer name and null plant component
     */
    PlantOrder();
    
    /**
     * @brief Destructor for PlantOrder
     */
    ~PlantOrder();
    
    /**
     * @brief Sets the customer name for this order
     * @param name The name of the customer
     */
    void setCustomerName(const std::string& name);
    
    /**
     * @brief Sets the plant component for this order
     * Takes ownership of the provided plant component pointer
     * @param component Pointer to a PlantComponent
     */
    void setPlantComponent(PlantComponent* component);
    
    /**
     * @brief Gets the customer name
     * @return The name of the customer who placed this order
     */
    std::string getCustomerName() const;
    
    /**
     * @brief Gets the plant component associated with this order
     * @return Pointer to the PlantComponent in this order
     */
    PlantComponent* getPlantComponent() const;
    
    /**
     * @brief Displays the complete order information
     */
    void display();
};

#endif
