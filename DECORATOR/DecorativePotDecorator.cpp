#include "DecorativePotDecorator.h"
#include <fstream>

DecorativePotDecorator::DecorativePotDecorator(Plant *plant):PlantDecorator(plant)
{}

double DecorativePotDecorator::getPrice()
{ 
  wrappedPlant->setPrice(wrappedPlant->getPrice() + 100.00);
  return wrappedPlant->getPrice() + 100.00; 
}

void DecorativePotDecorator::display()
{
  std::ifstream myfile ("DECORATOR/pot.txt");
  std::cout << std::endl << wrappedPlant->getName() << " + Pot for your plant (R100.00)\n";
  std::string line;
  while ( getline (myfile,line) )
  {  std::cout << line << '\n'; }
  myfile.close();
}

Plant* DecorativePotDecorator::clone() const
{ return wrappedPlant->clone(); }