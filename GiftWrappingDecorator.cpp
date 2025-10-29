#include "GiftWrappingDecorator.h"
#include <fstream>


GiftWrappingDecorator::GiftWrappingDecorator(Plant *plant):PlantDecorator(plant)
{}

double GiftWrappingDecorator::getPrice()
{  
  wrappedPlant->setPrice(wrappedPlant->getPrice() + 25.00);
  return wrappedPlant->getPrice() + 25.00; 
}

void GiftWrappingDecorator::display()
{
  std::ifstream myfile ("DECORATOR/gift.txt");
  std::cout << std::endl << wrappedPlant->getName() << " + Gift Wrapping (R25.00)\n";
  std::string line;
  while ( getline (myfile,line) )
  {  std::cout << line << '\n'; }
  myfile.close();
  
}

Plant* GiftWrappingDecorator::clone() const
{ return wrappedPlant->clone(); }