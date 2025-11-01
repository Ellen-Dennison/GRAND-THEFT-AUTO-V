/**
 * @file Observer.h
 * @brief Abstract observer interface for the observer pattern
 *
 * The Observer pattern creates a one-to-many dependency between objects, where one object, the subject, changes state , all its dependents (observers) are notified and updated automatically.
 *
 * Design Pattern: Observer (Observer interface)
 * Related Classes: Subject, StaffObserver, ManagerObserver, NurseryMediator
 */
#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>

/**
 * class Observer
 * @brief Abstract base class for observer objects
 */
class Observer {
public:

    /**
 * @brief Virtual destructor for proper cleanup of derived classes
 */

    virtual ~Observer() {}

/**
 * @brief Receives notification from subject
 * @param message String describing the event that occurred
 *
 * @per message should not be empty
 * @post Observer has processed the notification and taken appropriate action
 */
virtual void update(const std::string& message) =0;

/**
 * @brief Gets the observer's name or identifier
 * @return String identifying the observer
 */
virtual std::string getName() const {
    return "Observer";
}

/**
 * @brief Gets the observer's role or type
 * @return String describing the observer's role
 */
virtual std::string getRole() const {
    return "Observer";
}

/**
 * @brief Checks if observer is active
 * @return true if observer should not receive notifications, false otherwise
 */
virtual bool isActive() const {
    return true;
 }
};


#endif //OBSERVER_H
