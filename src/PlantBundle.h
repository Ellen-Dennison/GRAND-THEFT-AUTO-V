#ifndef PLANTBUNDLE_H
#define PLANTBUNDLE_H
#include <iostream>
#include <vector>
#include "PlantComponent.h"

/**
 * @class PlantBundle
 * @brief Create a bundle of cumsters
 * 
 *
 * Responsibilities include:
 * - Creating new plants through factories
 * - Managing plant lifecycle (growth, care, sale readiness)
 * - Handling customer interactions and orders
 * - Saving and restoring plant states (Memento pattern)
 * - Monitoring plant health and progress
 */

class PlantBundle:public PlantComponent
{  
  private: 
        /** @brief Collection of plants currently in the greenhouse (growing stage). */
        std::string bundleName;
        std::vector<PlantComponent*> items;
        double discount;

  public: 
        /**
         * @brief Adds a new plant of the given type to the greenhouse.
         * @param plantType The string name of the plant type (e.g., "Flower", "Tree").
        */
        PlantBundle(std::string bundleName, double discount);
        ~PlantBundle();
        void add( PlantComponent* item );
        void remove( PlantComponent* item );
        void display() const override;
        double getTotalValue() const override;
        virtual int getCount() const override;
    
};

#endif