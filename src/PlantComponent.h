/**
 * @file PlantComponent.h
 * @brief Composite participant of the composite pattern
 */
#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H
#include "Plant.h"
#include <iostream>


/**
 * @class PlantComponent
 * @date  01/11/2025
 * @brief The abstract base class for the PlantItem and PlantBundle
 */


class PlantComponent
{   

    public:

         /** 
         * @brief This function will display this portion of the customers order or their complete order when implemented by the derived classes
         */
        virtual void display() const = 0;
          
         /** 
         * @brief This is the function will return an int value with the price of an item(s) when implemented by the derived classes 
         */ 
        virtual double getTotalValue() const = 0;
     
         /** 
         * @brief This is the function will return the amount of the items within the bundle and one in the PlantItem derived class
         */
        virtual int getCount() const  = 0;

         /** 
         * @brief The is the PlantComponent destructor
         */
        virtual ~PlantComponent() {};

};

#endif