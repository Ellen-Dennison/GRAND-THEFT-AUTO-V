#include "PlantItem.h"
#include <iomanip> 
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
    
    //Check for decorators using typeid
    std::string className = typeid(*plant).name();
    bool hasDecorativePot = (className.find("DecorativePot") != std::string::npos);
    bool hasGiftWrap = (className.find("GiftWrapping") != std::string::npos);
    
    //Display extras if present
    if (hasDecorativePot || hasGiftWrap) {
        std::cout << "EXTRAS: ";
        
        if (hasDecorativePot) {
            std::cout << "🪴 Decorative Pot (+R100.00)";
        }
        if (hasGiftWrap) {
            if (hasDecorativePot) std::cout << ", ";
            std::cout << "🎁 Gift Wrapping (+R25.00)";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price💸 " << BLUE << plant->getPrice() << RESET << std::endl; 
    std::cout << "=====================\n"; 
}

std::string PlantItem::getName() const
{return plant->getName();}


double PlantItem::getTotalValue() const
{ return plant->getPrice(); }

int PlantItem::getCount() const
{ return 1; } 
