#include "PlantBundle.h"
#include "../data/colours.h"
#include <ctime>

void PlantBundle::display() const 
{  
   time_t timestamp;
   time(&timestamp);
   std::cout << "\nHere's is your final order\n";  
   std::cout << "========GRAND THEFT AUTO V========" << std::endl; 
   std::cout << "\t" << bundleName << std::endl; 
   std::cout << "\t" << ctime(&timestamp)  << std::endl;
   for (auto i = 0u; i < items.size(); i++) 
   { 
     items[i]->display(); 
   }

    double price = 0;
    for (auto i = 0u; i < items.size(); i++) 
    { price += items[i]->getTotalValue(); }
 
   std::cout << "Subtotal💸 : " << RED << price << RESET << std::endl; 
   std::cout << "Total with discount💰 :  " << BOLDRED  << this->getTotalValue() << RESET << std::endl; 
   

}

PlantBundle::PlantBundle(std::string bundleName, double discount)
{
    this->bundleName =  bundleName;
    this->discount = discount;
}

PlantBundle::~PlantBundle()
{   
   for (auto i = 0u; i < items.size(); i++) 
   {
      if( items[i] != nullptr )
      { delete items[i]; }
   }
   items.clear();
}

void PlantBundle::add( PlantComponent* item ) 
{ items.push_back(item); }

void PlantBundle::remove(PlantComponent* item){
   for (auto i = 0u; i < items.size(); i++) {
    if( items[i] == item){        
      delete items[i];
      items.erase(items.begin() + i); 
      break;
      }
   }
}

double PlantBundle::getTotalValue() const 
{    
    double discountPrice = 0;
    for (auto i = 0u; i < items.size(); i++) 
    { discountPrice += items[i]->getTotalValue(); }
    discountPrice -= (discountPrice * (discount/100.00));
    return discountPrice;
    
}

int PlantBundle::getCount() const
{ return items.size(); }


