#include "GiftWrappingDecorator.h"
#include <fstream>


GiftWrappingDecorator::GiftWrappingDecorator(Plant *p)
    : PlantDecorator(p)
{}

double GiftWrappingDecorator::getPrice() const{  
  return wrappedPlant->getPrice() + 25.00; 
}

void GiftWrappingDecorator::display() const{
    wrappedPlant->display();
    std::cout<<wrappedPlant->getName() << " with gift Wrapping at a extra R25.00 fee" << std::endl;
    std::cout << "Total Price: R" << getPrice() << std::endl;  
}

Plant* GiftWrappingDecorator::clone() const{ 
    return new GiftWrappingDecorator(wrappedPlant->clone());
}
