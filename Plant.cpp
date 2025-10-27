#include "Plant.h"

Plant::Plant(std::string name, std::string type, double price,std::string plant)
{
  this->name = name;
  this->type = type;
  this->price = price;
  this->plant = plant;
  
}

Plant::~Plant()
{}