/**
 * @file GiftWrappingDecorator.h
 * @brief One of the ConcreteDecorators
 */
#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H

#include "PlantDecorator.h"
#include "Plant.h"


 /**
 * @class GiftWrappingDecorator
 * @date  01/11/2025
 * @brief  Derived decorator class (inheirts from PlantDecorator); will be adding "Giftwrapping to the plant object"
 */
class GiftWrappingDecorator : public PlantDecorator
{   
    public:
          
         /**
         * @brief This is the GiftWrappingDecorator constructor and it initializes the members of the Base class
         * @param p The plant object that is to be wrapped to add extra functionality
         */
        GiftWrappingDecorator(Plant* p);

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
