
#ifndef STAFFOBSERVER_H
#define STAFFOBSERVER_H

#include "Observer.h"
#include <string>


class StaffObserver : public Observer{
private:
    std::string staffName;
    std::string role;

    bool active;

public:
    StaffObserver(const std::string& staffName, const std::string& staffRole);
    ~StaffObserver();

    void update (const std::string& message) override;
     std::string getName() const override;

     std::string getRole() const override;

     bool isActive() const override;

     void setActive(bool status);

     void display() const;

     void handleEvent(const std::string& details);

};


#endif //STAFFOBSERVER_H
