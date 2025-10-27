#include <iostream>
#include <string>

#include "FACTORY/TreeFactory.h"
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

  //std::cout << "DECORATOR\n";
  

  return 0;
}