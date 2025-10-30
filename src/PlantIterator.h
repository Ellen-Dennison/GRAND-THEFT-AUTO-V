#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include <vector>
#include "Iterator.h"
#include "Plant.h"

#include <iostream>
using namespace std;


class PlantIterator:public Iterator<Plant>{
    
    
    vector<Plant*>& plants;
    size_t position;
    
    public:
    
    PlantIterator(vector<Plant*>& p);
    virtual bool hasNext();
    virtual Plant* next();
    virtual void reset();
};






#endif