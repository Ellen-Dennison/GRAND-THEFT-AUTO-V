/**
 * @file Command.h
 * @brief Abstract command interface for the command
 *
 * The Command pattern encapsulates nursery operations as objects allowing for parameterization of operations, queueing, logging and potentially undoing operations.
 *
 * Design Pattern: Command (Command interface)
 * Related Classes: WaterPlantsCommand, AdvanceTimeCommand, RevivePlantCommand
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

/**
 * @class Command
 * @brief Abstract base class for all command objects
 */
class Command {
public:

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */

    virtual ~Command(){}

    /**
     * @brief Executes the command
     *
     * @post The operation encapsulated by the command is performed
     *
     * @note Concrete implementations should handle any necessary error checking
     * @note Some commands may modify system state, notify observers, etc.
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command (optional)
     *
     * @note Default implementation is empty
     * @note Override in derived classes to provide undo functionality
     */
    virtual void undo(){}

    /**
 * @brief Gets a description of the command
 *
 * @return A string describing the command's operation
 * @note Default implementation returns a generic message
 * @note Concrete commands should override to provide specific descriptions
 */
    virtual std::string getDescription() const{
        return "Command";
    }

    /**
     * @brief Checks if the command can be undone
     *
     * @return true if the command supports undo(), false otherwise
     *
     * @note Default implementation returns false
     * @note override in derived classes that implement undo()
     */
    virtual bool isUndoable() const {
        return false;
    }

};


#endif //COMMAND_H