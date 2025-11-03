/**
 * @file ManagerObserver.h
 * @brief Concrete observer implementation for nursery manager
 * Design Pattern: Observer (Concrete Observer)
 * Related Classes: Subject, Observer,NurseryMediator , StaffObserver
 */
#ifndef MANAGEROBSERVER_H
#define MANAGEROBSERVER_H

#include "Observer.h"
#include <map>
#include <string>


/**
 * class ManagerObserver
 * @brief Concrete observer representing the nursery manager
 */

class ManagerObserver:public Observer{
private:
    /**
 * @brief Name of the manager
 */
    std::string name;


    /**
     * @brief Total revenue tracked
     */
    double totalRevenue;

    /**
     * @brief Total number of sales
     */
    int totalSales;

    /**
     * @brief Map of plant sales by type
     */
    std::map<std::string, int> plantSalesCount;

    /**
     * @brief Number of plant deaths
     */
    int successfulRevivals;

    /**
     * @brief Initialized to 0 in constructor
     */
    int plantDeaths;

    /**
     * @brief Active status of the manager
     */
    bool active;

    /**
 * @brief Extracts the type of plant mentioned in a message
 * @param message The message string that potentially contains a plant type
 * @return std::string The extracted plant type, or an empty string if none found.
 */
    std::string extractPlantType(const std::string& message) const ;

    /**
 * @brief Extracts the price value from a given message string.
 * @param message The message string that potentially contains a price
 * @return double The extracted price value.Returns 0.0 if no valid price is found.
 */
    double extractPrice(const std::string& message) const;

public:
    /**
     * @brief Constructs a ManagerObserver with a name
     * @param managerName Name of the manager
     * @pre managerName should not be empty
     * @post Manager observer is created with zero statistics and active status
     */
    ManagerObserver(const std::string& managerName);

    /**
 * @brief Destructor for ManagerObserver
 */
    ~ManagerObserver();

    /**
   * @brief Receives and processes notification from subject
   * @param message String describing the event that occurred
   *
   * @post Manager statistics are updated based on event type
     * @post Manager provides analytical response
   */
     void update(const std::string& message) override;

    /**
  * @brief Gets the manager's name
  * @return The manager's name
  */
    std::string getName() const override;


    /**
  * @brief Gets the manager's role
  * @return "Manager"
  */
    std::string getRole() const override;

    /**
   * @brief Checks if the manager is active
   * @return true if active, false if inactive
   */
    bool isActive() const override;


    /**
 * @brief Sets the active status of the manager
 * @param status true to activate, false to deactivate
 * @post Manager's active status is updated
 */
    void setActive(bool status);

    /**
     * @brief Gets the total revenue tracked
     *
     * @return Total revenue in Rands
     */
    double getTotalRevenue() const;

    /**
  * @brief Gets the total number of sales
  *
  * @return Total number of sales
  */
    int getTotalSales() const;

    /**
     * @brief Gets sales count for a specific plant type
     * @param plantType Type of plant
     * @return Number of sales for that plant type, or 0 if not found
     */
    int getPlantSalesCount(const std::string& plantType ) const;

    /**
     * @brief Gets the best-selling plant type
     * @return Name of best-selling plant type, or empty string if no sales
     */
    std::string getBestSellingPlant() const;

    /**
     * @brief Gets the number of successful revivals
     * @return Number of successful plant revivals
     */
    int getSuccessfulRevivals() const;

    /**
     * @brief Gets the number of plant deaths
     * @return Number of plant deaths
     */
    int getPlantDeaths() const;

    /**
     * @brief Calculates the revival success rate
     * @return Revival success rate as percentage
     */
    double getRevivalSuccessRate() const;

    /**
     * @brief Displays comprehensive statistics summary
     *
     * Statistics summary includes:
     * - Total revenue and sales count
     * - Sales breakdown by plant type
     * - Best-selling plant
     * - Revival success rate
     * - Plant mortality rate
     */
    void displayStatistics() const;

    /**
     * @brief Resets all statistics to zero
     * @post All counters and maps are reset to initial values
     */
    void resetStatistics();


    /**
 * @brief Displays manager information
 */
    void display() const;





};









#endif