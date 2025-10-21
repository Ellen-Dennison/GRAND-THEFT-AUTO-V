#include "PlantMemento.h"

PlantMemento::PlantMemento(string state, int age, int health){
    
    this->state=state;
    this->age=age;
    this->health=health;
}

string PlantMemento::getState(){
    
    return state;
}

int PlantMemento::getAge(){
    
    return age;
}


int PlantMemento::getHealth(){
    
    return health;
}

void PlantMemento::display(){
      
      cout<<"state of the plant: "<<state<<endl;
      cout<<"Plant age: "<<age<<endl;
      cout<<"plant health: "<<health<<endl;
}
    