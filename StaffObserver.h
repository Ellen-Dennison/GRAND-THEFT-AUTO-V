#ifndef STAFFOBSERVER_H
#define STAFFOBSERVER_H


#include <iostream>
using namespace std;

#include "Observer.h"



class StaffObserver:public Observer{
    
 string staffName;
 
 
 public:
 
 StaffObserver(string name);
 virtual void update(string event);
    
    
    
    
};














#endif