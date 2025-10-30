#include "PlantItem.h"
#include "colours.h"


PlantItem::PlantItem(Plant* p)
{ this->plant = p; }

PlantItem::~PlantItem()
{
}

void PlantItem::display()
{   
    std::cout << WHITE << "\n******************************************" << RESET;  
    std::cout << "\n\t\t" << plant->getType() << std::endl; 
    std::cout << "YOUR ITEM: " << BLUE << plant->getName() << std::endl << RESET; 
    std::cout << "PRICE: " << BLUE << plant->getPrice() << std::endl; 
    std::cout << WHITE  << "******************************************\n" << RESET;  
}



double PlantItem::getTotalValue()
{ return plant->getPrice(); }

int PlantItem::getCount()
{ return 1; } 