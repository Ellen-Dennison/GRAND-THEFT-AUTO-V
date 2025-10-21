#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include <vector>
#include "Iterator.h"

class PlantIterator : public Iterator<Plant> {
    std::vector<Plant*>& plants;
    size_t position;
    
public:
    PlantIterator(std::vector<Plant*>& p);
    bool hasNext() override;
    Plant* next() override;
    void reset() override;
};

#endif
