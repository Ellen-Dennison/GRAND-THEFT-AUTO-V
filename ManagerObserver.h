#ifndef MANAGEROBSERVER_H
#define MANAGEROBSERVER_H



#include <iostream>
using namespace std;

#include "Observer.h"



class ManagerObserver:public Observer{
    
 string ManagerName;
 
 
 public:
 
 ManagerObserver(string name);
 virtual void update(string event);
    
    
    
    
};









#endif