/**
 * @file DecorativePotDecorator.h
 * @brief One of the ConcreateDecorators
 */
#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H

#include "PlantDecorator.h"
#include "Plant.h"

 /**
 * @class DecorativePotDecorator
 * @date  01/11/2025
 * @brief  Derived decorator class (inheirts from PlantDecorator), will be adding "a DecorativePot to the plant object"
 */
class DecorativePotDecorator : public PlantDecorator{   
    public:

         /**
         * @brief This is the DecorativePotDecorator constructor and it initializes the members of the Base class
         * @param p The plant object that is to be wrapped to add extra functionality
         */
        DecorativePotDecorator(Plant* p);
         
         /**
         * @brief Gets the price of the plant
         * @return Double with plant price
         */
        double getPrice() const override;
         
         /**
         * @brief Displays the plant information 
         */
        void display() const override;

         /**
         * @brief Create a deep copy of the private member plant object  
         * @return Pointer to the cloned plant
         */
        Plant* clone() const override;
};

#endif
