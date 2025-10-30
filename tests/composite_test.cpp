#include "doctest.h"
#include "../src/PlantItem.h"

#include "../src/Plant.h"
#include "../src/Flower.h"

TEST_CASE("Testing the function customer adding more items to the order")
{   
   Plant *f1 = new Flower("Clover", 44.77);
   PlantItem *p1 = new PlantItem(f1);
   CHECK(p1->getTotalValue() == 44.77);
   CHECK(p1->getTotalValue() == 12.77);
   CHECK(p1->getName() == "lover");
   delete p1;
   delete f1;

}

TEST_CASE("Testing the composite portion of the composite design pattern")
{

    
}
