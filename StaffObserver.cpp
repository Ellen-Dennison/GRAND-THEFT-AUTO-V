
#include "StaffObserver.h"
#include <iostream>
#include <algorithm>

StaffObserver::StaffObserver(const std::string& staffName, const std::string& staffRole) : name(staffName), role(staffRole), active(true) {
    std::cout << name << " (" << role << ") has joined the nursery team." << std::endl;
}

StaffObserver::~StaffObserver(){
    std::cout << name < " (" << role << ") has left the nursery team." << std::endl;
}

void update (const std::string& message) override;


std::string StaffObserver::getName() const {
    return name;
}

std::string StaffObserver::getRole() const {
    return role;
}

bool StaffObserver::isActive() const {
    return active;
}

void StaffObserver::setActive(bool status){
    if ( status != active) {
        active = status;
        if(active) {
            std::cout << name << " is now active (back on duty)." << std::endl;

        }else{
            std::cout << name << " is now inactive (on break)." << std::endl;
        }
    }
}

void StaffObserver::display() const{
    std::cout << "\n------ Staff Member ------" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Role: " << role << std::endl;
    std::cout << "Status: " << (active ? "Active" : "Inactive") << std::endl;
    std::cout << "===================================" << std::endl;

}

void StaffObserver::handleEvent(const std::string& eventType, const std::string& details) {
    std::cout << name << " handling " << eventType << "event: " << details << std::endl;
}

std::string StaffObserver::extractPlantType(const std::string& message) const {
    std::vector <std::string> plantTypes = {"Ros", "Succulent", "Lavender", "Baobab"};
    for (const std::string &plantType: plantTypes) {
        if (message.find(plantType) != std::string::npos) {
            return plantType;
        }
    }

    return "";

}