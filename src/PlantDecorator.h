/**
 * @file PlantDecorator.h
 * @brief Base classs for the decorators
 */
#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <iostream>
#include <string>
#include "Plant.h"

/**
 * @class PlantDecorator
 * @date  01/11/2025
 * @brief abstract base class for GiftWrappingDecorator and DecorativePotDecorator
 */
class PlantDecorator : public Plant
{
  
protected:
      /** @brief The plant object that will be used wrapped by the decorators to add more functionality to the object */
    Plant* wrappedPlant;

public:
      /**
      * @brief This is the PlantDecorator constructor and it initializes the members of the class
      * @param p The plant object that will be wrapped by the derived plantdecorator classes to add extra functionality
      */
    PlantDecorator(Plant* p);
      
     /**
     * @brief The PlantDecorator destructor
     */
    virtual ~PlantDecorator();

     /**
     * @brief  Gets the name of the plant
     * @return String with the plant name
     */
    virtual std::string getName()const override;
      
     /**
     * @brief Gets the type of plant
     * @return String with the plant type
     */
    virtual std::string getType() const override;
     
     /**
     * @brief Gets the price of the plant
     * @return Double with plant price
     */
    virtual double getPrice() const override;
     
     /**
     * @brief Displays the plant information 
     */
    void display()const override;
      
     /**
     * @brief Create a deep copy of the private member plant object  
     * @return Pointer to the cloned plant
     */
    Plant* clone() const override = 0;
  
};

#endif
