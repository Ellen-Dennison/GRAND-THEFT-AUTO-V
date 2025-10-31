#include "doctest.h"
#include "../src/PlantItem.h"
#include "../src/PlantBundle.h"
#include "../src/Plant.h"
#include "../src/Flower.h"
#include "../src/Tree.h"
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

TEST_CASE("Testing the function customer adding more items to the order")
{   
   Plant *f1 = new Flower("Clover", 44.77);
   PlantItem *p1 = new PlantItem(f1);
   CHECK(p1->getTotalValue() == 44.77);
   CHECK(p1->getName() == "Clover");
   delete p1;

}

TEST_CASE("Testing the composite portion of the composite design pattern")
{
   
   Plant *f1 = new Flower("Clover", 44.77);
   Plant *f2 = new Flower("AloeVera", 17.27);
   Plant *t1 = new Tree("Maple", 67.76);
   Plant *t2 = new Tree("YellowWood", 1000.00);

   PlantBundle *p1 = new PlantBundle("test_1",50.00);
   std::vector<Plant*> plants;
   plants.push_back(f1); 
   plants.push_back(f2);
   plants.push_back(t1);
   plants.push_back(t2);
   CHECK(plants.size() == 4);

   std::vector<PlantItem*> PlantItems;
   for (int i = 0; i < 4; i++)
   { PlantItems.push_back(new PlantItem( plants[i]) ); }
   CHECK(PlantItems.size() == 4);

   for (int i = 0; i < 4; i++)
   { p1->add(PlantItems[i]); }
   CHECK(p1->getTotalValue() == 564.9);
   CHECK(p1->getCount() == 4);
    
   //p1->add();
   delete p1;


}
