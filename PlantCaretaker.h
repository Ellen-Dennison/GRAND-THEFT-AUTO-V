#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H



#include "PlantMemento.h"
#include <iostream>
#include <vector>

using namespace std;



class PlantCaretaker{
    
  vector <PlantMemento*> mementos;

  public:
  
  vector<PlantMemento*> getMementos();
  void saveMemento(PlantMemento* memento);
    
    
    
    
};





#endif