#include "doctest.h"
#include "../src/Plant.h"
#include "../src/Flower.h"
#include "../src/SeedlingState.h"
#include "../src/GrowingState.h"
#include "../src/MatureState.h"
#include "../src/FloweringState.h"
#include "../src/WiltingState.h"
#include "../src/DeadState.h"

TEST_CASE("Plant State Transitions")
{

    Flower* flower = new Flower("Tulip", 109.99);

    SUBCASE("Seedling state initially"){
        CHECK(flower->getState() == "Seedling");
        CHECK(flower->getAge() == 0);
        CHECK(flower->getHealth() == 100);
        CHECK(flower->isReadyForSale() == false);
    }

    //Grow for 4 weeks then transition to grwoing
    for(int i = 0; i<4; i++){
        flower->water();
        flower->grow();
    }

    SUBCASE("After growing 4 weeks with watering"){
        //Check if in correct state
        CHECK(flower->getState() == "Growing");
        CHECK(flower->getAge() == 4);
        CHECK(flower->getHealth() == 95);
        CHECK(flower->isReadyForSale() == false);
    }

    //Grow 4 more times to 8 weeks and Go to mature
    for(int i = 0; i<4; i++){
        flower->water();
        flower->grow();
    }   
    SUBCASE("After growing 8 weeks with watering"){
        //Check if in correct state
        CHECK(flower->getState() == "Mature");
        CHECK(flower->getAge() == 8);
        CHECK(flower->getHealth() == 95);
        CHECK(flower->isReadyForSale() == true);

    }

    //Grow 4 more times to 12 weeks and Go to Flowering
    for(int i = 0; i < 6; i++){
        flower->water();
        flower->grow();
    }   
    
    SUBCASE("After 14 weeks with care - Flowering"){
        CHECK(flower->getState() == "Flowering");
        CHECK(flower->getAge() == 14);
        CHECK(flower->getHealth() == 95);
        CHECK(flower->isReadyForSale() == true);
    }

    //Now neglet so it can go to wilting state
    for(int i = 0; i<4; i++){ //health should be a 50
        flower->grow();
        //no water so it can wither
    }

    SUBCASE("10 weeks of neglect. will be in wilting"){        
        //Check if in correct state
        CHECK(flower->getState() == "Wilting");
        //CHECK(flower->getNeglectCounter() >= 4);
        //CHECK(flower->getHealth() < 100);
        CHECK(flower->isReadyForSale() == false);
    }

    //grow until plant dies to put it in deadState
    while(flower->getState() != "Dead" && flower->getAge() < 30){
        flower->grow();
    }

    SUBCASE("After being neglected for many weeks...PLANT DIES!"){        
        //Check if in correct state
        CHECK(flower->getState() == "Dead");
        CHECK(flower->getHealth() == 0);
        CHECK(flower->isReadyForSale() == false);
    }

    delete flower;
}
