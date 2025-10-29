#include "FlowerFactory.h"
#include <fstream>

Plant* FlowerFactory::createPlant()
{  
  std::ifstream myfile ("FACTORY/Flower.txt");
  std::cout <<  "You have created your " << name << " Flower\n";
  while ( getline (myfile,this->plant) )
  { 
    std::cout << this->plant << '\n'; 
  }
  myfile.close();
  return new Flower(name,type,price);   

}

std::string FlowerFactory::getFactoryType()
{ return "This is the FlowerFactory\n"; }