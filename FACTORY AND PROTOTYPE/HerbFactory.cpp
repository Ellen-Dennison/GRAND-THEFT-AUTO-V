#include "HerbFactory.h"
#include <fstream>

std::string HerbFactory::getFactoryType()
{ return "This is the HerbFactory\n"; }


Plant* HerbFactory::createPlant()
{  
  std::ifstream myfile ("FACTORY/Herb.txt");
  std::cout <<  "You have created your " << name << " Herb\n";
  while ( getline (myfile,this->plant) )
  { 
    std::cout << this->plant << '\n'; 
  }
  myfile.close();
  return new Herb(name,type,price);   

}