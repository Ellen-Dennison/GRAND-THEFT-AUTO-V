/**
 * @file FlowerFactory.h
 * @brief The Derived class of the PlantFactory. Dubbed the ConcreteCreator of the factory method
 */
#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H

#include "PlantFactory.h"
#include "Flower.h"


/**
 * @class FlowerFactory
 * @date  01/11/2025
 * @brief Factory that will be in-charge of creating Flower(derived plant) objects
 */
class FlowerFactory : public PlantFactory 
{
private:
    Plant* prototype;
    std::string flowerName;
    double flowerPrice;

public: 
      /**
      * @brief This is the FlowerFactory constructor and it initializes the members of the object
      * @param Name The string the name that will be given to the plant object
      * @param price The double containing the price that will be given to the plant object
      */
    FlowerFactory(std::string name, double price);

      /**
      * @brief The FlowerFactory destructor
      */
    ~FlowerFactory();

      /**
      * @brief Creates a plant object
      * @return Pointer to newly created plant object
      */
    Plant* createPlant() override;

      /**
      * @brief Gets the type of Factory
      * @return String with the Factory type
      */
    std::string getFactoryType() const override;
};

#endif
