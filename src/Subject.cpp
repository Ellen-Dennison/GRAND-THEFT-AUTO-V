

#include "Subject.h"
#include <iostream>
#include <algorithm>

void Subject::attach(Observer* observer){
    if (observer == nullptr) {
        std::cerr << "Error: Cannot attach null observer" << std::endl;
        return;
    }
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()){
        std::cerr << "Warning: Observer " << observer->getName() << " is already attached" << std::endl;
        return;
    }
    observers.push_back(observer);
    std::cout << "Observer " << observer->getName() << " (" << observer->getRole() << ") attached to subject" << std::endl;
}


void Subject::detach(Observer* observer){
    if (observer == nullptr) {
        std::cerr << "Error: Cannot detach null observer" << std::endl;
        return;
    }
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()){
        std::cout << "Observer " << observer->getName() << " (" << observer->getRole() << ") detached from subject" << std::endl;
        observers.erase(it);
    }else{
        std::cerr << "Warning: Observer" << observer->getName()<< " was not attached" << std::endl;

    }
}
void Subject::notify(const std::string& message){
    if(message.empty()){
        std::cerr << "Warning: Attempting to notify with empty messages" << std::endl;
        return;
    }
    if(observers.empty()){
        return;
    }

    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << " NOTIFICATION: " << message << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    int activeCount = 0;
    int inactiveCount =0;

    for(Observer* observer : observers){
        if(observer != nullptr){
            if (observer->isActive()){
                observer->update(message);
                activeCount++;
            } else {
                inactiveCount++;
            }
        }else{
            std::cerr << "Warning: Null observer found in list, skipping..." << std::endl;

        }
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << " Notified " << activeCount << " active observer(s)";
    if(inactiveCount > 0){
        std::cout << " (" << inactiveCount << " inactive)";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------\n" << std::endl;

}

int Subject::getObserverCount() const{
    return static_cast<int>(observers.size());
}
void Subject::detachAll(){
    if(observers.empty()){
        std::cout << "No observers to detach." << std::endl;
        return;
    }
    int count = observers.size();
    observers.clear();

    std::cout << "All " << count << " observer(s) detached from subject" << std::endl;
}


bool Subject::isAttached(Observer* observer) const {
    if (observer == nullptr) {
        return false;
    }
    auto it = std::find(observers.begin(), observers.end(), observer);
    return (it != observers.end());


}


void Subject::displayObservers() const{
    std::cout << "\n===== Attached Observers =====" << std::endl;

    if(observers.empty()) {
        std::cout << "No observers currently attached." << std::endl;
    }else{
        std::cout << "Total Observers: " << observers.size() << std::endl;
        std::cout << "\nObserver List:" << std::endl;
        std::cout << "------------------------------" << std::endl;

        int index = 1;
        int activeCount = 0;
        int inactiveCount = 0;

        for(const Observer* observer : observers){
            if(observer != nullptr){
                std::cout << index << ". " << observer->getName() << " (" << observer->getRole() << ")";

                if(observer->isActive()){
                    std::cout << " - Active";
                    activeCount++;
                }else{
                    std::cout << " - Inactive";
                    inactiveCount++;
                }
                std::cout << std::endl;

                index++;
            }
        }
        std::cout << "------------------------------" << std::endl;
        std::cout << "Active: " << activeCount << " | Inactive: " << inactiveCount << std::endl;



    }
    std::cout << "===================================\n" << std::endl;
}