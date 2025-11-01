/**
 * @file PlantItem.h
 * @brief leaf participant of the composite pattern
 */
#ifndef PLANTITEM_H
#define PLANTITEM_H
#include "PlantComponent.h"


/**
 * @class PlantItem
 * @date  01/11/2025
 * @brief Creates a PlantComponent item from the customer's needed plant.
 * 
 * Responsibilities include:
 * - returns the total price of the plant object
 * - returns the plant name
 */


class PlantItem:public PlantComponent
{
  private:

        /** @brief The plant object that will be used by PlantBundle to create the final order */
      Plant* plant;

  public:

        /**
         * @brief This PlantItem constructor and it initializes the members of the object
         * @param p The plant object that will used by the PlantItem and PlantBundle to create the final order 
         */
      PlantItem(Plant* p);
      
        /** 
         * @brief The is the PlantItem destructor
         */
      virtual ~PlantItem();

        /** 
         * @brief This function will return the plants name when needed by the PlantBundle
         * @return string with the plant name 
         */
      std::string getName() const;
         
         /** 
         * @brief This function will display this portion of the customers order so one plant item
         */ 
      virtual void display() const;

         /** 
         * @brief This is the function will return the price of the private  plant member attribute 
         * @return returns the price of the plant object
         */
      virtual double getTotalValue() const;
         
        /** 
         * @brief This function will be used to return the total amount of the items within the bundle 
         * @return an int of the value one
         */
      virtual int getCount() const; 


};

#endif