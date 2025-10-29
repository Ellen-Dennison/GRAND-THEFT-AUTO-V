
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <string>
#include <algorithm>

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& message);

    int getObserverCount() const;
    void detachAll();
    bool isAttached(Observer* observer) const;
    void displayObservers() const;

};


#endif //SUBJECT_H
