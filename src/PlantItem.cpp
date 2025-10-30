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
    std::cout << WHITE << "\n******************************************" << RESET;  
    std::cout << "\n\t\t" << plant->getType() << std::endl; 
    std::cout << "YOUR ITEM: " << BLUE << plant->getName() << std::endl << RESET; 
    std::cout << "PRICE: " << BLUE << plant->getPrice() << std::endl; 
    std::cout << WHITE  << "******************************************\n" << RESET;  
}

std::string PlantItem::getName() const
{return plant->getName();}


double PlantItem::getTotalValue() const
{ return plant->getPrice(); }

int PlantItem::getCount() const
{ return 1; } 