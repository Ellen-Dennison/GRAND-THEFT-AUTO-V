/**
 * @file PlantCaretaker.h
 * @brief Management of plant memento storage
 *
 * This class implements the Caretaker role in the Memento pattern.
 * It manages a collection of PlantMemento objects, providing storage and retrieval functionality for plant state snapshots.
 *
 * Design Pattern: Memento (Caretaker role)
 * Related Classes: PlantMemento (Memento), Plant (Originator)
 */

#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H



#include "PlantMemento.h"
#include <map>
#include <string>

/**
 * @class PlantCaretaker
 * @brief Manages the storage and retrieval of plant mementos
 */


class PlantCaretaker{
private:

    /**
     *@brief Map storing mementos indexed by plant identifier
     *
     * key: Plant identifier
     * Value: Pointer to PlantMemento object
     */
    std::map<std::string, PlantMemento*> mementos;

public:

    /**
     * @brief Default constructor for PlantCaretaker
     * Initializes an empty caretaker with no stored mementos
     * Memento map gets populated as plants save their states
     */
    PlantCaretaker();

    /**
     * @brief Destructor for PlantCaretaker
     *
     * Iterates through the map and deletes all PlantMemento objects preventing memory leaks
     */
    ~PlantCaretaker();

    /**
     * @brief Saves a memento with the given plant identifier
     * @param plantId Unique identifier for the plant
     * @param memento Pointer to the PlantMemento to be stored
     *
     * @pre memento must not be nullptr
     * @pre plantId must not be empty
     *
     * @post The memento is stored in the map and accessible via the plantId
     * @post If a previous memento existed for plantId, it is deleted
     *
     * @note The caretaker takes ownership of memento pointer
     */
    void saveMemento(const std::string& plantId, PlantMemento* memento);

    /**
     * @brief Retrieves a memento by plant identifier
     * @param plantId The unique identifier of the plant
     * @return Pointer to the stored PlantMemento, or nullptr if not found
     *
     * @pre plantId must not be empty
     *
     * @note Returns nullptr if no memento exists for the given plantId
     * @note The caretaker retains ownership of the returned pointer
     */

    PlantMemento* getMemento(const std::string& plantId) const;


    /**
     * @brief Checks if a memento exists for a given plant ID
 * @param plantId The unique identifier of the plant
 * @return true if a memento exists for the plant, false otherwise
 *
 * @pre plantId must not be empty
 */
    bool hasMemento(const std::string& plantId) const;

    /**
     * @brief Remove a memento from storage
     *
     * @param plantId The unique identifier of the plant
     * @return true if the memento was found and deleted, false if not found
     *
     * @post If memento existed, it is deleted and removed from the map
     * @post If memento didn't exist, map remains unchanged
     */

    bool deleteMemento(const std::string& plantId);

    /**
     * @brief Gets the number of stored mementos
     * @return the total count of plant state snapshots currently in stored in the caretaker.
     *
     */
    int getMementoCount() const;

    /**
     * @brief Clears all stored mementos
     * @post All mementos are deleted and the map is empty
     * @post getMementoCount() returns 0
     */
    void clearAllMementos();

    /**
     * @brief Displays all stored mementos
     */
    void displayAllMementos() const;



};





#endif