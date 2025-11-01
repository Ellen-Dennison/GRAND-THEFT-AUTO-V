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
      * @brief This PlantDecorator constructor and it initializes the members of the object
      * @param p The plant object that will be wrapped by the derived plantdecorator classes to add extra functionality
      */
    PlantDecorator(Plant* p);
      
     /**
     * @brief Returns a pointer to the singleton instance of City.
     * @return A pointer to the City instance.
     */
    virtual ~PlantDecorator();

    virtual std::string getName()const override;

    virtual std::string getType() const override;

    virtual double getPrice() const override;

    void display()const override;

    Plant* clone() const override = 0;
  
};

#endif
