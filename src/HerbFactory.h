/**
 * @file HerbFactory.h
 * @brief The Derived class of the PlantFactory. Dubbed the ConcreteCreator of the factory method
 */
#ifndef HERBFACTORY_H
#define HERBFACTORY_H

#include "PlantFactory.h"
#include "Herb.h"

/**
 * @class HerbFactory
 * @date  01/11/2025
 * @brief Factory that will be in-charge of creating Herb(derived plant) objects
 */
class HerbFactory : public PlantFactory 
{
private:
    Plant* prototype;
    std::string herbName;
    double herbPrice;

public:
      /**
      * @brief This is the HerbFactory constructor and it initializes the members of the object
      * @param Name The string the name that will be given to the plant object
      * @param price The double containing the price that will be given to the plant object
      */
    HerbFactory(std::string name, double price);

      /**
      * @brief The HerbFactory destructor
      */
    ~HerbFactory();
     
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
