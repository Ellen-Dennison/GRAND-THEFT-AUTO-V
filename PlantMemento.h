#ifndef PLANTMEMENTO_H
#define PLANTMEMENTO_H

#include <iostream>
#include <string>
using namespace std;





class PlantMemento{
  
  string state;
  int age;
  int health;
  
  public:
  
  PlantMemento(string state, int age, int health);
  string getState();
  int getAge();
  int getHealth();
  void display();
    
    
    
    
};








#endif