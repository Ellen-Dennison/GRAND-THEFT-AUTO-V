/**
 * @file Iterator.h
 * @brief Defines a generic template interface for iterating over collections.
 *
 * This file provides a simple iterator interface template class, which 
 * defines the common operations for sequentially accessing elements of 
 * a collection without exposing its underlying structure.
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

/**
 * @class Iterator
 * @brief A generic abstract base class for creating custom iterators.
 *
 * The `Iterator` class defines the interface for iterating over a collection 
 * of objects of type `T`. It provides methods to check for the next element, 
 * access it, and reset the iteration. Concrete implementations (e.g., 
 * `PlantIterator`) must define the actual traversal logic.
 *
 * @tparam T The type of element to iterate over.
 *
 * ### Example:
 * ```cpp
 * Iterator<Plant>* it = new PlantIterator(plants);
 * while (it->hasNext()) {
 *     Plant* p = it->next();
 *     p->display();
 * }
 * it->reset();
 * delete it;
 * ```
 */
template <typename T>
class Iterator {
public:
    /**
     * @brief Checks whether there are more elements to iterate over.
     * @return `true` if there are more elements, otherwise `false`.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Returns the next element in the collection.
     * 
     * This method advances the iterator to the next element and returns a 
     * pointer to it. If no elements remain, the behavior is undefined 
     * unless guarded by `hasNext()`.
     *
     * @return A pointer to the next element of type `T`.
     */
    virtual T* next() = 0;

    /**
     * @brief Resets the iterator to the beginning of the collection.
     * 
     * After calling `reset()`, iteration can begin again from the first element.
     */
    virtual void reset() = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup in derived classes.
     */
    virtual ~Iterator() = default;
};

#endif // ITERATOR_H
