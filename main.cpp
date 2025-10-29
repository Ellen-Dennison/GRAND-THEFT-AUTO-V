#include <iostream>
#include <string>

#include "FACTORY AND PROTOTYPE/TreeFactory.h"
#include "DECORATOR/GiftWrappingDecorator.h"
#include "DECORATOR/DecorativePotDecorator.h"
#include "COMPOSITE/PlantItem.h"
#include "COMPOSITE/PlantComponent.h"
#include "COMPOSITE/PlantBundle.h"
#include "Tree.h"

int main()
{  

  std::cout << "FACTORIES\n";
  std::string name = "YellowWood";
  std::string type = "Tree";
  double price = 2500.55;

  //FACTORY
  TreeFactory* t1 = new TreeFactory;
  Plant* tree1 = t1->createPlant(name,type,price);

  //DELETE
  delete t1;
 

  std::cout << "-----------------------------------------------\n";
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
  
  std::cout << "-----------------------------------------------\n";
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