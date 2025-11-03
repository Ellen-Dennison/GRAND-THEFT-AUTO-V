#ifndef PLANTBUNDLE_H
#define PLANTBUNDLE_H
#include <iostream>
#include <vector>
#include "PlantComponent.h"

/**
 * @class PlantBundle
 * @date  01/11/2025
 * @brief Create a bundle from PlantItem objects which have a customer's plant order
 * 
 *
 * Responsibilities include:
 * - adding multiple items into one complete order
 * - calculating the total discount the custmer will receive on their bundle(order)
 * - providing the customer the ability to gauge the total price without the discount
 */

class PlantBundle:public PlantComponent
{  
  private: 
        /** @brief The name of the bundled order a customer is creating */
        std::string bundleName;

        /** @brief This will store the PlantItems; these are the individual items the customer wants to add to the order */
        std::vector<PlantComponent*> items;

        /** @brief The discount the customer will be receiving calculated by getting the total from all the PlantItems objects  stored within the items vector*/
        double discount;

  public: 

         /**
         * @brief This PlantBundle constructor and it initializes the members of the object
         * @param bundleName The string containing the bundle name 
         * @param discount The double containing the discount that will be applied to the order 
         */
        PlantBundle(std::string bundleName, double discount);

         /** 
         * @brief The is the PlantBundle destructor
         */ 
        ~PlantBundle();
        
         /** 
         * @brief This function will add an item to the items vector thus creating a bundle of orders
         */
        void add( PlantComponent* item );
         
         /** 
         * @brief This function will remove an item from the items order thus showing how a using can remove from their order
         */
        void remove( PlantComponent* item );

         /** 
         * @brief This function will display the customers order with every item they have requested to buy
         * including the total with discount
         */ 
        void display() const override;
        
         /** 
         * @brief This is the function will return the total value of the items within the bundle 
         * @return The total value of the Items within the bundle; no discount
         */ 
        double getTotalValue() const override;

         /** 
         * @brief The function calculates the total amount of items within the bundle 
         * @return the amount of items within the bundle
         */ 
        virtual int getCount() const override;
    
};

#endif