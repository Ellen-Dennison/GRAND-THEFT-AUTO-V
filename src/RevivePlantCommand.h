/**
 * @file RevivePlantCommand.h
 * @brief Concrete command for reviving wilting plants from saved states
 * Design Pattern: Command (ConcreteCommand Participant)
 * Related Classes: Command, Plant, PlantMemento, PlantCaretaker, WiltingState
 */

#ifndef REVIVEPLANTCOMMAND_H
#define REVIVEPLANTCOMMAND_H


#include "Command.h"
#include "Plant.h"
#include "PlantCaretaker.h"
#include <string>



/**
 * @class RevivePlantCommand
 * @brief Command that revives a wilting plant from a saved memento
 */
class RevivePlantCommand : public Command{
private:
    /**
     * @brief Pointer to the plant to be revived
     *
     * Stores a pointer to the Plant object that needs revival.
     * The plant must be in WiltingState for revival to succeed.
     */
    Plant* plant;

    /**
     * @brief Pointer to the caretaker storing plant mementos
     */
    PlantCaretaker* caretaker;

    /**
     * @brief Unique identifier for the plant
     */
    std::string plantIdentifier;

public:
    /**
 * @brief Constructs an RevivePlantCommand for a specific plant
 * @param targetPlant Pointer to the plant to be revived
 * @param PlantCaretaker Pointer to the caretaker storing mementos
 * @param id Unique identifier for the plant
 *
 * @pre targetPlant must not be nullptr
 * @pre plantCaretaker must not be nullptr
 * @pre id must not be empty and should match a saved memento
 * @post Command is ready to execute revival operation
 */
    RevivePlantCommand(Plant* targetPlant, PlantCaretaker* plantCaretaker, const std::string& id);

    /**
     * @brief Destructor for RevivalCommand
     */
    ~RevivePlantCommand();

    /**
     * @brief Executes the revival command
     * @post If successful, plant is restored to saved healthy state
     * @post If failed, plant remains in current state, error message displayed
     */
    void execute() override;


    /**
 * @brief Gets a description of the command
 * @return String describing the command
 */
    std::string getDescription() const override;

    /**
     * @brief Checks if the command can be undone
     * @return false- revival is not reversible
     */
    bool isUndoable() const override;

    /**
     * @brief Gets the plant identifier
     * @return the plant identifier string
     */
    std::string getPlant() const;

    /**
     * @brief Validates if revival is possible
     * @return true if revival conditions are met, false otherwise
     */
    bool canRevive() const;



};


#endif //REVIVEPLANTCOMMAND_H