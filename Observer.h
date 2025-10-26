
#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>


class Observer {
public:
    virtual ~Observer() {}

    virtual void update(const std::string& message) =0;
    virtual std::string getName() const {
        return "Observer";
    }

    virtual std::string getRole() const {
        return "Observer";
    }

    virtual bool isActive() const {
        return true;
    }
};


#endif //OBSERVER_H
