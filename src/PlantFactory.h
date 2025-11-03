/**
 * @file PlantFactory.h
 * @brief The Base class for the factories. Dubbed the Creator of the factory method
 */
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plant.h"
#include <string>
//#include <map>

/**
 * @class PlantFactory
 * @date  01/11/2025
 * @brief abstract base class for FlowerFactory, HerbFactory, SucculentFactory, TreeFactory
 */
class PlantFactory 
{
public:
     /**
     * @brief The PlantFactory destructor
     */
    virtual ~PlantFactory() {}

     /**
     * @brief Creates a plant object
     * @return Pointer to newly created plant object
     */
    virtual Plant* createPlant() = 0;
     
     /**
     * @brief Gets the type of Factory
     * @return String with the Factory type
     */
    virtual std::string getFactoryType() const = 0;
};

#endif
