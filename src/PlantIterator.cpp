#include "PlantIterator.h"

// Constructor
PlantIterator::PlantIterator(vector<Plant*>& p)
    : plants(p), position(0) {}

// Check if there are more plants left
bool PlantIterator::hasNext() {
    return position < plants.size();
}

// Return the next Plant* in the collection
Plant* PlantIterator::next() {
    if (hasNext())
        return plants[position++];
    else
        return NULL;
}

// Reset iteration to the beginning
void PlantIterator::reset() {
    position = 0;
}
