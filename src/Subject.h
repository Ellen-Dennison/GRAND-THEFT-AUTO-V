/**
 * @file Subject.h
 * @brief Abstract subject class for the Observer pattern
 * Maintains a list of observers and provides mechanisms to attach, detach, and notify them when significant events occurred.
 * Design Pattern: Observer (Subject role)
 * Related Classes: Observer, StaffObserver, NurseryMediator , ManagerObserver
 */
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <string>
#include <algorithm>
/**
 * @class Subject
 * @brief Abstract base class for observable objects in the Observer pattern
 */
class Subject {
protected:
    /**
     * @brief List of observers attached to this subject
     */
    std::vector<Observer*> observers;

public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Subject() {}

    /**
     * @brief Attaches an observer to this subject
     * @param observer Pointer to the observer to be attached
     * @pre observer must not be nullptr
     * @post observer is added to the observers list
     * @post observer will receive future notifications
     */
    void attach(Observer* observer);

    /**
 * @brief Detaches an observer from this subject
 * @param observer Pointer to the observer to be detached
 * @pre observer must not be nullptr
 * @post observer is removed from the observers list
 * @post observer will not receive future notifications
 */
    void detach(Observer* observer);

    /**
 * @brief Notifies all attached observers of an event
 * @param message String describing the event that occurred
 * @pre message should not be empty
 * @post All active observers have been notified via update()
 * @post Inactive observers are skipped
 */
    void notify(const std::string& message);

    /**
     * @brief Gets the number of attached observers
     * @return Number of attached observers
     */
    int getObserverCount() const;

    /**
* @brief Detaches all observer from this subject
* @post observer list is empty
* @post No observer will receive future notifications
*/
    void detachAll();

    /**
 * @brief Checks if a specific observer is attached
 * @param observer Pointer to the observer to check
 * @return true if the observer is attached, false otherwise
 * @pre observer must not be nullptr
 */
    bool isAttached(Observer* observer) const;

    /**
     * @brief Displays information about attached observers
     *
     * Prints details about all currently attached observers such as their names, roles and active status.
     */
    void displayObservers() const;

};


#endif //SUBJECT_H
