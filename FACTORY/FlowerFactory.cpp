#include "FlowerFactory.h"
#include <fstream>

Plant* FlowerFactory::createPlant(std::string name, double price)
{  
  std::ifstream myfile ("FACTORY/Flower.txt");
  std::cout <<  "\nYou have created your " << name << " Flower\n";
  while ( getline (myfile,this->plant) )
  { 
    std::cout << this->plant << '\n'; 
  }
  myfile.close();
  return new Flower(name,price);   

}

std::string FlowerFactory::getFactoryType()
{ return "This is the FlowerFactory\n"; }