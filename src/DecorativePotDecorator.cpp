#include "DecorativePotDecorator.h"
#include <fstream>

DecorativePotDecorator::DecorativePotDecorator(Plant *p)
    : PlantDecorator(p)
{}

double DecorativePotDecorator::getPrice() const { 
  return wrappedPlant->getPrice() + 100.00; 
}

void DecorativePotDecorator::display() const{
    wrappedPlant->display();
    std::cout<<wrappedPlant->getName() <<" with decorative Pot at a R100.00 extra fee" << std::endl;
    std::cout <<"Total Price: R" << getPrice() << std::endl;
}

Plant* DecorativePotDecorator::clone() const{
    return new DecorativePotDecorator(wrappedPlant->clone()); 
}
