#include "TreeFactory.h"
#include <fstream>



std::string TreeFactory::getFactoryType()
{ return "This is the TreeFactory\n"; }

Plant* TreeFactory::createPlant(std::string name, double price)
{  
  std::ifstream myfile ("FACTORY/Tree.txt");
  std::cout <<  "\nYou have created your " << name << " Tree\n";
  while ( getline (myfile,this->plant) )
  { 
    std::cout << this->plant << '\n'; 
  }
  myfile.close();
  return new Tree(name,price); 

}