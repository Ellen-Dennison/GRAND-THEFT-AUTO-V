
#ifndef GRAND_THEFT_AUTO_V_SUBJECT_H
#define GRAND_THEFT_AUTO_V_SUBJECT_H

#include <vector>
#include <string>

class Observer;

class Subject {
private: // might change to protected
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}
    void attach(Observer* obs);
    void notify(const std::string& message);

};
#endif //GRAND_THEFT_AUTO_V_SUBJECT_H
