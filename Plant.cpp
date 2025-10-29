#include "Plant.h"
/* #include "SeedlingState.h"
#include "GrowingState.h"
#include "MatureState.h"
#include "FloweringState.h"
#include "WiltingState.h"
#include "DeadState.h"
#include "DailyWateringStrategy.h"
#include "BiWeeklyWateringStrategy.h"
#include "WeeklyWateringStrategy.h" */

#include <iostream>

Plant::Plant(std::string n, std::string t, double p):
    name(n), type(t), price(p) /*,age(0), healthLevel(100), neglectCounter(0) */
    {

       /*  currState = new SeedlingState();
        currState->setPlant(this);
        wateringStrategy = NULL;
        sunlightNeeds = PARTIAL_SHADE;
        fertilizerNeeds = MONTHLY_FERTILIZER;
        optimalSeason = SPRING; */
    }
/* 
Plant::Plant(const Plant& other) 
    : name(other.name), 
      type(other.type), 
      price(other.price), 
      age(other.age), 
      healthLevel(other.healthLevel), 
      neglectCounter(other.neglectCounter),
      sunlightNeeds(other.sunlightNeeds),
      fertilizerNeeds(other.fertilizerNeeds),
      optimalSeason(other.optimalSeason) {
    
    // Deep copy state to create new state object
    std::string stateName = other.currState->getStateName();
    if (stateName == "Seedling") {
        currState = new SeedlingState();
    } else if (stateName == "Growing") {
        currState = new GrowingState();
    } else if (stateName == "Mature") {
        currState = new MatureState();
    } else if (stateName == "Flowering") {
        currState = new FloweringState();
    } else if (stateName == "Wilting") {
        currState = new WiltingState();
    } else if (stateName == "Dead") {
        currState = new DeadState();
    } else {
        currState = new SeedlingState();  // default
    }
    currState->setPlant(this);
    
    // Deep copy watering strategy to create NEW strategy object
    if (other.wateringStrategy) {
        // Check which strategy it is and create a new one
        std::string schedule = other.wateringStrategy->getWateringSchedule();
        if (schedule.find("Daily") != std::string::npos) {
            wateringStrategy = new DailyWateringStrategy();
        } else if (schedule.find("Weekly") != std::string::npos && schedule.find("Bi") == std::string::npos) {
            wateringStrategy = new WeeklyWateringStrategy();
        } else if (schedule.find("Bi-weekly") != std::string::npos) {
            wateringStrategy = new BiWeeklyWateringStrategy();
        } else {
            wateringStrategy = nullptr;
        }
    } else {
        wateringStrategy = nullptr;
    }
}

Plant::~Plant(){
    delete currState;
    delete wateringStrategy;
}

void Plant::setState(PlantState* state){
    delete currState;
    currState = state;
    currState->setPlant(this);
}

void Plant::setWateringStrategy(WateringStrategy* strategy){
    if(wateringStrategy!=strategy){
        delete wateringStrategy;
        wateringStrategy = strategy;
    }
}

void Plant::grow(){
    age++;
    
    incrementNeglect();//if plant isnt being cared for
    
    //If neglect low enoug to put plant in poor condition
    if (neglectCounter >= 4 && currState->getStateName() != "Dead" && currState->getStateName() != "Wilting") {
        std::cout << "WARNING: " << name << " neglected for " << neglectCounter << " weeks." << std::endl;
        std::cout << name << " is now entering Wilting state" << std::endl;
        setState(new WiltingState());
    }
    
    //If condition too poor that it goes into wilting state
    if (currState->getStateName() != "Wilting" && currState->getStateName() != "Dead") {
        if (healthLevel < 30) {
            std::cout << "WARNING: " << name << " is wilting due to poor health." << std::endl;
            setState(new WiltingState());
        }
    }
    
    currState->grow();
}

void Plant::water(){
    if(wateringStrategy){    
        wateringStrategy->water(this);
        resetNeglect();
    }
}

void Plant::provideSunlight() {
    std::cout << "Providing ";
    if (sunlightNeeds == FULL_SUN) std::cout << "full sun exposure";
    else if (sunlightNeeds == PARTIAL_SHADE) std::cout << "partial shade";
    else std::cout << "full shade protection";
    std::cout << " - Health +3" << std::endl;
    adjustHealth(3);
    resetNeglect();
}

void Plant::fertilize() {
    std::cout << "Fertilizing plant - Health +8" << std::endl;
    adjustHealth(8);
    resetNeglect();
}

void Plant::adjustHealth(int amount) {
    healthLevel+=amount;

    if(healthLevel>100){
        healthLevel=100;
    }

    if(healthLevel < 0){
        healthLevel = 0;
    }
}

void Plant::incrementNeglect() {
    neglectCounter++;
    
    if (neglectCounter > 0) {
        int healthLoss = neglectCounter *5;  //More neglect = more health loss
        adjustHealth(-healthLoss);
        std::cout << name << " neglected (Week " << neglectCounter<< ") - Health -" << healthLoss << std::endl;
    }
    
    if (neglectCounter >= 4 && currState->getStateName() != "Dead") {
        //This will be handled in grow() to avoid duplicate messages
    }
}

void Plant::resetNeglect() {
    neglectCounter = 0;
} */

/*PlantMemento* Plant::createMemento() const {
    return new PlantMemento(currState->getStateName(), age, healthLevel);
}

void Plant::restoreFromMemento(PlantMemento* memento) {
    healthLevel = memento->getHealth();
    
    std::string savedState = memento->getState();
    if (savedState == "Seedling") {
        setState(new SeedlingState());
    } else if (savedState == "Growing") {
        setState(new GrowingState());
    } else if (savedState == "Mature") {
        setState(new MatureState());
    } else if (savedState == "Flowering") {
        setState(new FloweringState());
    }
    
    resetNeglect();
    std::cout << name << " restored to " << savedState 
              << " state with " << healthLevel << "% health]" << std::endl;
}

void Plant::revivePlant(PlantMemento* memento) {
    if (currState->getStateName() == "Wilting") {
        std::cout << "Attempting to revive " << name<<"..."<< std::endl;
        //std::cout << "Using saved memento from healthier time..." << std::endl;
        restoreFromMemento(memento);
        std::cout <<name << " successfully revived!" << std::endl;
    } else if (currState->getStateName() == "Dead") {
        std::cout << "Cannot revive " << name << " - plant is dead" << std::endl;
    } else {
        std::cout << name << " doesn't need revival - Plant is healthy" << std::endl;
    }
}*/

std::string Plant::getName() const{ 
    return name; 

}
std::string Plant::getType() const{ 
    return type; 
}

double Plant::getPrice() const{
    return price;
}

void Plant::setPrice(double p){ 
    price = p; 
}

/* int Plant::getAge() const{ 
    return age; 
}

int Plant::getHealth() const{ 
    return healthLevel; 
}

int Plant::getNeglectCounter() const{ 
    return neglectCounter;
}

std::string Plant::getState() const{ 
    return currState->getStateName();
}

bool Plant::isReadyForSale() const{ 
    return currState->canBeSold() && healthLevel > 60;
}

std::string Plant::getWateringInfo() const{ 
    return wateringStrategy->getWateringSchedule();
}


bool Plant::isInOptimalSeason(GrowthSeason currSeason) const {
    return optimalSeason == ALL_SEASONS || optimalSeason == currSeason;
}

std::string Plant::getSunlightDescription() const {
    if (sunlightNeeds == FULL_SUN) return "Full Sun (6+ hours)";
    if (sunlightNeeds == PARTIAL_SHADE) return "Partial Shade (3-6 hours)";
    return "Full Shade (<3 hours)";
}

std::string Plant::getFertilizerDescription() const {
    if (fertilizerNeeds == WEEKLY_FERTILIZER) return "Weekly Fertilizing";
    if (fertilizerNeeds == MONTHLY_FERTILIZER) return "Monthly Fertilizing";
    if (fertilizerNeeds == SEASONAL_FERTILIZER) return "Seasonal Fertilizing";
    return "No Fertilizer Needed";
}
 */


/* std::string Plant::getSeasonDescription() const {
    switch(optimalSeason){
        case SPRING:
            return "Spring";
        case SUMMER:
            return "Summer";
        case AUTUMN:
            return "Autumn";
        case WINTER:
            return "Winter";
        default:
            return "All Seasons";
    }
}

void Plant::display() const {
    std::cout << "Plant: " << name << " | Type: " << type << std::endl;
    std::cout << "State: " << currState->getStateName()
              << " | Age: " << age << " weeks | Health: " << healthLevel << "%" << std::endl;
    std::cout << "Price: R" << price << " | Neglect Counter: " << neglectCounter << std::endl;
    std::cout << "Watering Info: " << getWateringInfo() << std::endl;
    std::cout << "Sunlight: " << getSunlightDescription() << std::endl;
    std::cout << "Fertilizer: " << getFertilizerDescription() << std::endl;
    std::cout << "Optimal Season: " << getSeasonDescription() << std::endl;
    std::cout << "Ready for Sale: " << (isReadyForSale() ? "Yes" : "No") << std::endl;
} */
