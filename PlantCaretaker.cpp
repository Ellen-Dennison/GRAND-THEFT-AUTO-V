#include "PlantCaretaker.h"


vector <PlantMemento*> PlantCaretaker::getMementos(){
     
     return mementos;
}
 
void PlantCaretaker::saveMemento(PlantMemento* memento){
    
    mementos.push_back(memento);
   cout<<"plant state saved: ";
   memento->display();
   
} 
 