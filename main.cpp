#include <iostream>
#include <string>

#include "FACTORY/TreeFactory.h"
#include "DECORATOR/GiftWrappingDecorator.h"
#include "DECORATOR/DecorativePotDecorator.h"
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
  delete tree1;

  std::cout << "-----------------------------------------------\n";
  std::cout << "DECORATORS\n";

  //GIFT DECORATOR
  Plant* tree2 = new Tree("Maple","Tree",1800.75);
  GiftWrappingDecorator* finalPlant =  new GiftWrappingDecorator(tree2);
  finalPlant->display();
  std::cout << "Here is your final price " << finalPlant->getPrice() << std::endl;

  //POT DECORATOR
  Plant* tree3 = finalPlant->clone();
  DecorativePotDecorator* finalPlant2 =  new DecorativePotDecorator(tree3);
  finalPlant2->display();
  std::cout << "Here is your final price " << finalPlant2->getPrice() << std::endl;
  

  //DELETE
  delete tree2;
  delete tree3;
  delete finalPlant;
  delete finalPlant2;
  

  return 0;
}