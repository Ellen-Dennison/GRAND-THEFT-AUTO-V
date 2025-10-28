#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
template <typename T>
class Iterator{
    public:
    virtual bool hasNext()=0;
    virtual T* next()=0;
    virtual void reset()=0;
    ~Iterator();
};



#endif