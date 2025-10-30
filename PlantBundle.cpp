#include "PlantBundle.h"
#include "colours.h"
#include <ctime>

void PlantBundle::display() const 
{  
   time_t timestamp;
   time(&timestamp);
   std::cout << "\nHere's is your final order\n";
   std::cout << WHITE << "\n******************************************\n" << RESET;  
   std::cout << "\t" << "GRAND THEFT AUTO V" << std::endl; 
   std::cout << "\t" << bundleName << std::endl; 
   std::cout << "\t" << ctime(&timestamp)  << std::endl;
   for (int i = 0; i < items.size(); i++) 
   { 
     items[i]->display(); 
   }

    double price = 0;
    for (int i = 0; i < items.size(); i++) 
    { price += items[i]->getTotalValue(); }
 
   std::cout << "SUBTOTAL : " << RED << price << RESET << std::endl; 
   std::cout << "TOTAL WITH DISCOUNT : " << BOLDRED  << this->getTotalValue() << RESET << std::endl; 
   std::cout << WHITE << "\n******************************************\n" << RESET;  


}

PlantBundle::PlantBundle(std::string bundleName, double discount)
{
    this->bundleName =  bundleName;
    this->discount = discount;
}

PlantBundle::~PlantBundle()
{   
   for (int i = 0; i < items.size(); i++) 
   {
      if(items[i] != nullptr)
      { delete items[i]; }
   }
   items.clear();
}

void PlantBundle::add( PlantComponent* item ) 
{ items.push_back(item); }

void PlantBundle::remove( PlantComponent* item ) 
{
   for (int i = 0; i < items.size(); i++) 
   {
    if(items[i] == item)
    { items.erase(items.begin() + i); }
   }
}

double PlantBundle::getTotalValue() const 
{    
    double discountPrice = 0;
    for (int i = 0; i < items.size(); i++) 
    { discountPrice += items[i]->getTotalValue(); }
    discountPrice -= (discountPrice * (discount/100.00));
    return discountPrice;
    
}

int PlantBundle::getCount() 
{ return items.size(); }