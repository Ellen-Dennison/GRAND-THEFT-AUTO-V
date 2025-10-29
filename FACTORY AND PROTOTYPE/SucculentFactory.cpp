#include "SucculentFactory.h"
#include <fstream>



std::string SucculentFactory::getFactoryType()
{ return "This is the SucculentFactory\n"; }


Plant* SucculentFactory::createPlant(std::string name, std::string type, double price)
{  
  std::ifstream myfile ("FACTORY/Succulent.txt");
  std::cout <<  "You have created your " << name << " Succulent\n";
  while ( getline (myfile,this->plant) )
  { 
    std::cout << this->plant << '\n'; 
  }
  myfile.close();
  return new Succulent(name,type,price);  

}