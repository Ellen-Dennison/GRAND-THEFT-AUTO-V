/**
 * @file PlantIterator.h
 * @brief Defines the PlantIterator class for iterating over a collection of Plant objects.
 *
 * The `PlantIterator` class provides a concrete implementation of the generic `Iterator` interface,
 * allowing sequential access to elements in a collection of `Plant` pointers without exposing
 * the underlying container structure.
 */

#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include <vector>
#include <iostream>
#include "Iterator.h"
#include "Plant.h"

using namespace std;

/**
 * @class PlantIterator
 * @brief Concrete iterator for traversing a collection of Plant objects.
 *
 * Implements the `Iterator<Plant>` interface to provide a standard way
 * of iterating over a list or vector of `Plant*` elements.
 * 
 * This class keeps track of the current iteration position and provides
 * methods to check if more elements exist, retrieve the next element, 
 * and reset the iteration back to the start.
 *
 * ### Example:
 * ```cpp
 * vector<Plant*> greenhousePlants = mediator.getGreenhouse();
 * PlantIterator it(greenhousePlants);
 * 
 * while (it.hasNext()) {
 *     Plant* plant = it.next();
 *     cout << "Plant: " << plant->getName() << endl;
 * }
 * ```
 */
class PlantIterator : public Iterator<Plant> {
private:
    /** @brief Reference to the collection of plants being iterated over. */
    vector<Plant*>& plants;

    /** @brief Current position in the iteration sequence. */
    size_t position;

public:
    /**
     * @brief Constructs a new iterator for the given collection of plants.
     * @param p Reference to a vector of `Plant*` elements to iterate over.
     */
    PlantIterator(vector<Plant*>& p);

    /**
     * @brief Checks if there are more plants to iterate over.
     * @return `true` if there is at least one more plant, otherwise `false`.
     */
    virtual bool hasNext();

    /**
     * @brief Returns the next `Plant` in the collection.
     * 
     * Advances the iterator position by one. If there are no more elements,
     * the behavior is undefined (should be checked using `hasNext()`).
     *
     * @return Pointer to the next `Plant` object.
     */
    virtual Plant* next();

    /**
     * @brief Resets the iterator to the beginning of the collection.
     */
    virtual void reset();
};

#endif // PLANTITERATOR_H
