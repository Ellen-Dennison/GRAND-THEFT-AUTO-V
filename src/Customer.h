/**
 * @file Customer.h
 * @brief Declares the Customer class used to simulate a nursery customer.
 *
 * The Customer class models an individual who browses, interacts with, 
 * and purchases plants from the nursery. 
 * It manages customer details (name, budget) and behaviors such as 
 * browsing the sales floor, making purchases, or requesting customization.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"

/**
 * @class Customer
 * @brief Represents a nursery customer who can browse, interact, and purchase plants.
 *
 * The Customer class provides functionality for interacting with plants 
 * available in the sales floor of the nursery. Each customer has a name 
 * and a defined budget that limits their ability to make purchases.
 *
 * Responsibilities:
 * - Browsing the sales floor (viewing available plants)
 * - Checking affordability based on budget
 * - Expressing interest or requesting customization
 * - Making purchases and reducing their available budget
 */
class Customer {
private:
    /** @brief The customer's name. */
    std::string name;

    /** @brief The customer's current available budget. */
    double budget;

public:
    /**
     * @brief Constructs a Customer with a given name and budget.
     * @param n The customer's name.
     * @param b The customer's initial budget.
     */
    Customer(std::string n, double b);

    /**
     * @brief Retrieves the customer's name.
     * @return The customer's name as a string.
     */
    std::string getName() const;

    /**
     * @brief Retrieves the customer's available budget.
     * @return The customer's current budget as a double.
     */
    double getBudget() const;

    /**
     * @brief Allows the customer to browse available plants on the sales floor.
     * 
     * Displays information about each plant such as name, type, and price.
     *
     * @param salesFloor A reference to a vector of Plant pointers representing available plants.
     */
    void browseSalesFloor(std::vector<Plant*>& salesFloor);

    /**
     * @brief Determines if the customer can afford a plant based on its price.
     * @param price The price of the plant to check.
     * @return True if the price is within the customer's budget, otherwise false.
     */
    bool canAfford(double price) const;

    /**
     * @brief Simulates the customer asking for a plant recommendation.
     * 
     * Outputs a message representing the customer’s inquiry.
     */
    void askForRecommendation();

    /**
     * @brief Expresses interest in a specific plant.
     * @param plantName The name of the plant the customer is interested in.
     */
    void expressInterest(std::string plantName);

    /**
     * @brief Requests a customization option for a plant (e.g., pot or wrapping).
     * @param customType A string describing the type of customization.
     */
    void requestCustomisation(std::string customType);

    /**
     * @brief Simulates the customer making a purchase.
     * 
     * Deducts the specified amount from the customer’s budget if affordable.
     * Displays success or failure messages.
     *
     * @param amount The amount spent on the purchase.
     */
    void makePurchase(double amount);
};

#endif // CUSTOMER_H
