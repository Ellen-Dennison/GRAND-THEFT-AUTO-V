#ifndef PLANTITEM_H
#define PLANTITEM_H
#include "PlantComponent.h"


/**
 * @class PlantItem
 * @date  01/11/2025
 * @brief Creates a PlantComponent item from the customer's needed plant.
 * 
 * Responsibilities include:
 * - returns the total price of the plant object
 * - returns the plant name
 */


class PlantItem:public PlantComponent
{
  private:

      /** @brief The plant object that will be used by PlantBundle to create the final order */
      Plant* plant;

  public:

       /**
       * @brief This PlantItem constructor and it initializes the members of the object
       * @param p The plant object that will used by the PlantItem and PlantBundle to create the final order 
       */
      PlantItem(Plant* p);
      
     
      virtual ~PlantItem();
        /** 
         * @brief This is the function will return the total value of the items within the bundle 
         * @return The total value of the Items within the bundle; no discount
         */
      std::string getName() const;

      virtual void display() const;

         /** 
         * @brief This is the function will return the total value of the items within the bundle 
         * @return The total value of the Items within the bundle; no discount
         */
      virtual double getTotalValue() const;
         
        /** 
         * @brief This is the function will return the total value of the items within the bundle 
         * @return The total value of the Items within the bundle; no discount
         */
      virtual int getCount() const; 


};

#endif