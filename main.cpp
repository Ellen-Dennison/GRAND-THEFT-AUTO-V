#include <iostream>
#include <string>

#include "FACTORY/TreeFactory.h"
#include "FACTORY/FlowerFactory.h"
#include "FACTORY/HerbFactory.h"
#include "DECORATOR/GiftWrappingDecorator.h"
#include "DECORATOR/DecorativePotDecorator.h"
#include "COMPOSITE/PlantItem.h"
#include "COMPOSITE/PlantComponent.h"
#include "COMPOSITE/PlantBundle.h"
#include "Tree.h"
#include "Flower.h"
#include "Herb.h"

int main()
{  

  std::cout << "FACTORIES\n";
  std::string name = "YellowWood";
  std::string type = "Tree";
  double price = 2500.55;

  //TREE FACTORY
  TreeFactory* t1 = new TreeFactory;
  Plant* tree1 = t1->createPlant(name,type,price);
  std::cout << "\n******************************************\n";

  //FLOWER FACTORY
  FlowerFactory* f1 = new FlowerFactory;
  Plant* flower1 = f1->createPlant("Sunflower","Flower", 67.00);
  std::cout << "\n******************************************\n";

  //HERB FACTORY
  HerbFactory* h1 = new HerbFactory;
  Plant* herb1 = h1->createPlant("Thyme","Herb", 20.00);

  //DELETE
  delete t1;
  delete f1;
  delete h1;
  delete flower1;
  delete herb1;

 

  std::cout << "\n******************************************\n";
  std::cout << "DECORATORS\n";

  //GIFT DECORATOR
  Plant* tree2 = new Tree("Maple","Tree",1800.75);
  GiftWrappingDecorator* finalPlant =  new GiftWrappingDecorator(tree2);
  finalPlant->display();
  std::cout << "Here is your final price " << finalPlant->getPrice() << std::endl;

  //POT DECORATOR
  Plant* tree3 = finalPlant->clone();
  Plant* tree4 = new Tree("Oak","Tree",3000.75);
  DecorativePotDecorator* finalPlant2 =  new DecorativePotDecorator(tree3);
  finalPlant2->display();
  std::cout << "Here is your final price " << finalPlant2->getPrice() << std::endl;
  
  std::cout << "\n******************************************\n";
  std::cout << "COMPOSITES\n";
  PlantComponent* item1 = new PlantItem(tree1);
  PlantComponent* item2 = new PlantItem(tree2);
  PlantComponent* item3 = new PlantItem(tree3);
  PlantComponent* item4 = new PlantItem(tree4);
  PlantBundle* Pc2 = new PlantBundle("Order_1", 50.00);
 

  //COMPOSITE
  //item1->display();

  //BUNDLES
  Pc2->add(item1);
  Pc2->add(item2);
  Pc2->add(item3);
  Pc2->add(item4);
  Pc2->display();



  //DELETE
  delete tree1;
  delete tree2;
  delete tree3;
  delete tree4;
  delete finalPlant;
  delete finalPlant2;
  delete item1;
  delete item2;
  delete item3;
  delete item4;
  delete Pc2;
  

  return 0;
}