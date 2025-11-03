/**
 * @file TreeFactory.h
 * @brief The Derived class of the PlantFactory. Dubbed the ConcreteCreator of the factory method
 */
#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "PlantFactory.h"
#include "Tree.h"

/**
 * @class TreeFactory
 * @date  01/11/2025
 * @brief Factory that will be in-charge of creating Tree(derived plant) objects
 */
class TreeFactory : public PlantFactory {
private:
    Plant* prototype;
    std::string treeName;
    double treePrice;

public:
      /**
      * @brief This is the TreeFactory constructor and it initializes the members of the object
      * @param Name The string the name that will be given to the plant object
      * @param price The double containing the price that will be given to the plant object
      */
    TreeFactory(std::string name, double price);
    
      /**
      * @brief The TreeFactory destructor
      */
    ~TreeFactory();

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
