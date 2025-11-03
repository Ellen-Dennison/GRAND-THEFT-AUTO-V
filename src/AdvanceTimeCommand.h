/**
 * @file AdvanceTimeCommand.h
 * @brief Concrete command for advancing plant growth over time
 * Design Pattern: Command (ConcreteCommand Participant)
 * Related Classes: Command, Plant, PlantState
 */

#ifndef ADVANCETIMECOMMAND_H
#define ADVANCETIMECOMMAND_H
#include "Command.h"
#include "Plant.h"
#include <vector>
#include <string>


/**
 * @class AdvanceTimeCommand
 * @brief Command that advances time and plant growth in the simulation
 */
class AdvanceTimeCommand : public Command{
private:
    /**
    @brief Reference to the collection of plants to be aged
     **/
    std::vector<Plant*>& plants;

    /**
     * @brief Number of weeks to advance
     */
    int weeks;

public:
    /**
     * @brief Constructs an AdvanceTimeCommand for a plant collection
     * @param plantCollection should contain valid Plant pointers
     * @param numWeeks Number of weeks to advance
     *
     * @pre plantCollection Reference to the vector of plants to age
     * @pre numWeeks should be non-negative
     * @post Command is ready to execute time advancement operation
     */
    AdvanceTimeCommand(std::vector<Plant*>& plantCollection, int numWeeks=1);

    /**
     * @brief Destructor for AdvanceTimeCommand
     */
    ~AdvanceTimeCommand();

    /**
     * @brief Executes the time advancement command
     * @post All plants have aged by the specified number of weeks
     * @post Plants may have transitioned to new life cycle states
     * @post Some plants may have entered wilting or dead states if neglected
     */
    void execute() override;

    /**
     * @brief Gets a description of the command
     * @return String describing the command
     */
    std::string getDescription() const override;

    /**
     * @brief Checks if the command can be undone
     *
     * Time advancement cannot be undone so this method always returns false
     * @return false - aging cannot be reversed
     */
    bool isUndoable() const override;

    /**
     * @brief Gets the number of weeks to advance
     * @return The number of weeks stored in this command
     */

    int getWeeks() const;

    /** @brief Sets the number of weeks to advance
     *
     * Modifies the time duration of this command.
     *
     * @param numWeeks New number of weeks to advance
     *
     * @pre numWeeks should be non-negative
     * @post The command will use the new week count on next execute()
     */

    void setWeeks(int numWeeks);

    /**
     * @brief Gets the number of plants affected
     * @return The number of plants in the collection
     */
    int getPlantCount() const;



};


#endif //ADVANCETIMECOMMAND_H