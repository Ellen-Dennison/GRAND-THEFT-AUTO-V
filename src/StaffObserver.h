/**
 * @file StaffObserver.h
 * @brief Concrete observer implementation for nursery staff memebers
 *
 * The Observer pattern creates a one-to-many dependency between objects, where one object, the subject, changes state , all its dependents (observers) are notified and updated automatically.
 *
 * Design Pattern: Observer (Concrete Observer)
 * Related Classes: Subject, Observer,NurseryMediator
 */
#ifndef STAFFOBSERVER_H
#define STAFFOBSERVER_H

#include "Observer.h"
#include <string>


class StaffObserver : public Observer{
private:
    std::string staffName;
    std::string role;

    bool active;

    std::string extractPlantType(const std::string& message) const ;


        public:
    StaffObserver(const std::string& staffName, const std::string& staffRole);
     ~StaffObserver();

    void update (const std::string& message) override;
     std::string getName() const override;

     std::string getRole() const override;

     bool isActive() const override;

     void setActive(bool status);

     void display() const;

     void handleEvent(const std::string& eventType, const std::string& details);

};


#endif //STAFFOBSERVER_H
