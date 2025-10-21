#include "Plant.h"



Plant::Plant(string name,string type,double price){
    this->name=name;
    this->type=type;
    this->price=price;
    
}

Plant::~Plant(){}


PlantMemento* Plant::createMemento(){
    
    PlantMemento* m1= new PlantMemento("germination",31,45);
    cout<<"snap created: ";
    m1->display();
    return m1;
}


void Plant::setWateringStrategy(WateringStrategy* strategy){
    
    this->strategy=strategy;
}


 string Plant::getName(){
     return name;
 }
  
 string Plant::getType(){
      return type;
  }