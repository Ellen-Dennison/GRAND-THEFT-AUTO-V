#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using  namespace std;


class Observer{
    
    
    
    virtual void update(string event)=0;

};


#endif