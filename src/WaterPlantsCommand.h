/**
 * @file WaterPlantsCommand.h
 * @brief Concrete command for watering all plants in a collection
 * Design Pattern: Command (ConcreteCommand Participant)
 * Related Classes: Command, Plant, WateringStrategy
 */
#ifndef WATERPLANTSCOMMAND_H
#define WATERPLANTSCOMMAND_H
#include "Command.h"
#include "Plant.h"
#include <vector>
#include <string>

/**
 * @class WaterPlantsCommand
 * @brief Command that waters all plants in a collection
 */

class WaterPlantsCommand : public Command{
private:

    /**
     * @brief Reference to the collection of plants to be watered
     *
     * @note Uses reference to avoid copying the entire vector
     */
    std::vector<Plant*>& plants;

public:

    /**
 * @brief Constructs a WaterPlantsCommand for a given plant collection
 * Creates a command that will water all plants in the provided collection when executed.
 *
 * @param plantCollection Reference to the vector of plants to be watered
 * @post Command is ready to execute watering operation
 */
    WaterPlantsCommand(std::vector<Plant*>& plantCollection);

    /**
     * @brief Destructor for WaterPlantsCommand
     */
    ~WaterPlantsCommand();

    /**
 * @brief Executes the watering command
 *
 * @post All plants in the collection have been watered
 * @post Each plant's health is increased according to its strategy
 * @post Plants maintain maximum health cap (typically 100)
 *
 * @note Handles empty collections gracefully
 * @note Does not throw exceptions for invalid plants
 */
    void execute() override;


    /**
 * @brief Gets a description of the command
 *
 * @return A string describing the command
 *
 */
    std::string getDescription() const override;

    /**
 * @brief Checks if the command can be undone
 *
 * Watering plants cannot be undone so this method returns false.
 *
 * @return false - watering is not reversible
 */
    bool isUndoable() const override;


    /**
     * @brief Gets the number of plants to be watered
     * @return The number of plants in the collection
     */
    int getPlantCount() const;



};


#endif //WATERPLANTSCOMMAND_H