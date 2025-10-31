#include "PlantItem.h"
#include "../data/colours.h"


PlantItem::PlantItem(Plant* p)
{ this->plant = p; }

PlantItem::~PlantItem()
{ 
  if (plant != nullptr)
  { delete plant; }
}

void PlantItem::display() const
{   
    std::cout << "\n=====================";  
    std::cout << "\n" << plant->getType() << std::endl; 
    std::cout << "Your item🛍️  " << BLUE << plant->getName() << std::endl << RESET; 
    std::cout << "Price💸 " << BLUE << plant->getPrice() << RESET << std::endl; 
    std::cout << "=====================\n";  
}

std::string PlantItem::getName() const
{return plant->getName();}


double PlantItem::getTotalValue() const
{ return plant->getPrice(); }

int PlantItem::getCount() const
{ return 1; } 