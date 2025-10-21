#include "ManagerObserver.h"



ManagerObserver::ManagerObserver(string name){
    ManagerName=name;
}



void ManagerObserver::update(string event){
    
    cout<<"Manager: "<<ManagerName<<" has received an update: "<<event<<endl;
}