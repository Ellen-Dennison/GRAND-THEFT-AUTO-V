/**
 * @file SucculentFactory.h
 * @brief The Derived class of the PlantFactory. Dubbed the ConcreteCreator of the factory method
 */
#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H

#include "PlantFactory.h"
#include "Succulent.h"

/**
 * @class SucculentFactory
 * @date  01/11/2025
 * @brief Factory that will be in-charge of creating Succulent(derived plant) objects
 */
class SucculentFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string succulentName;
    double succulentPrice;

public: 

      /**
      * @brief This is the SucculentFactory constructor and it initializes the members of the object
      * @param Name The string the name that will be given to the plant object
      * @param price The double containing the price that will be given to the plant object
      */
    SucculentFactory(std::string, double price);

      /**
      * @brief The SucculentFactory destructor
      */
    ~SucculentFactory();

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
