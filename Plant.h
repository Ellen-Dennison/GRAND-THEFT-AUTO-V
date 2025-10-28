#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
/* #include "Enums.h"
#include "WateringStrategy.h"
#include "PlantState.h"
#include "PlantMemento.h"
 */
class Plant{
protected:
    std::string name;
    std::string type;
    double price;
    int age;
    /*int healthLevel;
    int neglectCounter;
    PlantState* currState;
    WateringStrategy* wateringStrategy;
    SunlightRequirement sunlightNeeds;
    FertilizerFrequency fertilizerNeeds;
    GrowthSeason optimalSeason; */

public:
    Plant(std::string n, std::string t, double p);
    virtual ~Plant();
    virtual Plant* clone() const = 0;
    /*void setState(PlantState* state);
    void setWateringStrategy(WateringStrategy* strategy);
    void grow();
    void water();
    void provideSunlight();
    void fertilize();
    void adjustHealth(int amount);
    void incrementNeglect();
    void resetNeglect();
    PlantMemento* createMemento() const;
    void restoreFromMemento(PlantMemento* memento);
    void revivePlant(PlantMemento* memento); */
    std::string getName()const;
    std::string getType() const;
    double getPrice() const;
    virtual void setPrice(double p);
    int getAge() const;
 /*    int getHealth() const;
    int getNeglectCounter() const;
    std::string getState() const;
    bool isReadyForSale() const;
    std::string getWateringInfo() const;
    bool isInOptimalSeason(GrowthSeason currSeason) const;
    std::string getSunlightDescription() const;
    std::string getFertilizerDescription() const;
    std::string getSeasonDescription() const;
    virtual void display() const; */

};

#endif