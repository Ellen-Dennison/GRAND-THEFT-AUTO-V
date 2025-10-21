#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include "Plant.h"

template<typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() = 0;
    virtual T* next() = 0;
    virtual void reset() = 0;
};

#endif
