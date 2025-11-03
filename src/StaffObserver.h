/**
 * @file StaffObserver.h
 * @brief Concrete observer implementation for nursery staff members.
 * Design Pattern: Observer (Concrete Observer)
 * Related Classes: Subject, Observer,NurseryMediator
 */
#ifndef STAFFOBSERVER_H
#define STAFFOBSERVER_H

#include "Observer.h"
#include <string>


/**
 * class StaffObserver
 * @brief Concrete observer representing a staff member in the nursery
 */
class StaffObserver : public Observer{
private:
    /**
     * @brief Name of the staff member
     */
    std::string staffName;

    /**
     * @brief Role or position of the staff member
     */
    std::string role;

    /**
     * @brief Active status of the staff member
     */
    bool active;

    /**
     * @brief Extracts the type of plant mentioned in a message
     * @param message The message string that potentially contains a plant type
     * @return std::string The extracted plant type, or an empty string if none found.
     */
    std::string extractPlantType(const std::string& message) const ;


        public:
    /**
     * @brief Constructs a StaffObserver with name and role
     * @param staffName Name of the staff member
     * @param staffRole Role of the staff member
     *
     * @pre staffName should not be empty
     * @pre staffRole should not be empty
     * @post Staff observer is created and active
     */
    StaffObserver(const std::string& staffName, const std::string& staffRole);

    /**
     * @brief Destructor for StaffObserver
     */
     ~StaffObserver();

     /**
      * @brief Receives and processes notification from subject
      * @param message String describing the event that occurred
      *
      * @post Staff member has acknowledged and responded to the notification
      */
    void update (const std::string& message) override;

    /**
     * @brief Gets the staff member's name
     * @return The staff member's name
     */
     std::string getName() const override;

     /**
      * @brief Gets the staff member's role
      * @return The staff member's role
      */
     std::string getRole() const override;

     /**
      * @brief Checks if the staff member is active
      * @return true if active, false if inactive/on break
      */
     bool isActive() const override;

     /**
      * @brief Sets the active status of the staff member
      * @param status true to activate, false to deactivate
      * @post Staff member's active status is updated
      */
     void setActive(bool status);

     /**
      * @brief Displays staff member information
      */
     void display() const;

     /**
      * @brief Processes a specific event type
      * @param eventType Type of event
      * @param details Additional details about the event
      */
     void handleEvent(const std::string& eventType, const std::string& details);

};


#endif //STAFFOBSERVER_H
