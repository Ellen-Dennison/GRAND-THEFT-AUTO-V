#ifndef CONCRETESUBJECT_H
#define CONCRETESUBJECT_H


#include <iostream>

#include "Subject.h"



class ConcreteSubject{
    
    
  virtual void notify(Observer* obs);
  virtual void attach(Observer* obs);
  virtual void detach(Observer* obs);  
    
    
};



#endif