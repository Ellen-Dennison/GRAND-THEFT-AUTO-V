
#include "StaffObserver.h"
#include <iostream>
#include <algorithm>

StaffObserver::StaffObserver(const std::string& staffName, const std::string& staffRole) : name(staffName), role(staffRole), active(true) {
    std::cout << name << " (" << role << ") has joined the nursery team." << std::endl;
} // not sure about name and staffname

StaffObserver::~StaffObserver(){
    std::cout << name < " (" << role << ") has left the nursery team." << std::endl;
}

void StaffObserver::update (const std::string& message) {
    if(!active) {
        return;
    }

    std::cout << "\n[" << staffName << " (" << role << ")] Notification received:" << std::endl;
    std::cout << " ->" << message << std::endl;

    std::string lowerMessage = message;
    std::transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);


    if(role == "GreenhouseWorker") {
        if(lowerMessage.find("purchased") != std::string::npos) {
            std::string plantType = extractPlantType(message);
            if(!plantType.empty()) {
                std::cout << " " << staffName << ": Need to grow more " << plantType << " to restock!" << std::endl;
            } else{
                std::cout << " " << staffName << ": Need to grow more plants to restock!" << std::endl;

            }
        }
        else if (lowerMessage.find("wilting") != std::string::npos) {
            std::cout << " " << staffName << ": I'll check on it immediately and provide care!" << std::endl;
        }
        else if (lowerMessage.find("revived") != std::string::npos) {
            std::cout << " " << staffName << ": Great! I'll monitor it closely from now on." << std::endl;
        }
        else if (lowerMessage.find("new plant added") != std::string::npos) {
            std::cout << " " << staffName << ": I'll prepare the care schedule for the new arrival." << std::endl;
        }
        else if (lowerMessage.find("died") != std::string::npos) {
            std::cout << " " << staffName << ": I'll remove it and analyze what went wrong." << std::endl;
        }
        else if (lowerMessage.find("low stock") != std::string::npos) {
            std::cout << " " << staffName << ": I'll prioritize propagating more plants." << std::endl;
        }
    }

    else if(role == "SalesAssociate") {
        if(lowerMessage.find("purchased") != std::string::npos) {
            std::string plantType = extractPlantType(message);
            if(!plantType.empty()) {
                std::cout << " " << staffName << ": " << plantType << " is popular! I'll recommend this to other customers!" << std::endl;
            } else{
                std::cout << " " << staffName << ": I'll recommend this to other customers!" << std::endl;

            }
        }
        else if (lowerMessage.find("moved to sales floor") != std::string::npos) {
            std::cout << " " << staffName << ": New inventory available! I'll update the displays." << std::endl;
        }
        else if (lowerMessage.find("low stock") != std::string::npos) {
            std::cout << " " << staffName << ": I'll inform customers about limited availability." << std::endl;
        }
        else if (lowerMessage.find("customer") != std::string::npos) {
            std::cout << " " << staffName << ": I'll provide assistance right away!" << std::endl;
        }
        else if (lowerMessage.find("wilting") != std::string::npos) {
            std::cout << " " << staffName << ": I'll remove it from the sales floor display" << std::endl;
        }
        else if (lowerMessage.find("revived") != std::string::npos) {
            std::cout << " " << staffName << ": Good! I can put it back on display soon." << std::endl;
        }
    }

    else if(role == "DeliveryDriver") {
        if(lowerMessage.find("purchased") != std::string::npos) {

                std::cout << " " << staffName <<"I'll prepare for delivery!" << std::endl;
            } else if(lowerMessage.find("delivery") != std::string::npos){
                std::cout << " " << staffName << ": On it! Checking delivery schedule." << std::endl;

            }
        }

    else if(role == "Landscaper") {
        if(lowerMessage.find("arrangement") != std::string::npos || lowerMessage.find("bundle") != std::string::npos) {

            std::cout << " " << staffName <<"I'll create a beautiful arrangement!" << std::endl;
        } else if(lowerMessage.find("mature") != std::string::npos){
            std::cout << " " << staffName << ": Perfect timing for landacaping projects!" << std::endl;

        }
    }
    else if(role == "GreenHouseManager") {
        if(lowerMessage.find("wilting") != std::string::npos || lowerMessage.find("died") != std::string::npos) {

            std::cout << " " << staffName <<"I'll review our care protocols and staff performance." << std::endl;
        } else if(lowerMessage.find("new plant added") != std::string::npos){
            std::cout << " " << staffName << ": Noted. I'll oversee its growth cycle." << std::endl;

        }
        else if (lowerMessage.find("low stock") != std::string::npos) {
            std::cout << " " << staffName << ": I'll coordinate with the greenhouse team on production." << std::endl;
        }
    }
    else {
        std::cout << " " << staffName << ": Acknowledged." << std::endl;
    }



}


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
    std::vector <std::string> plantTypes = {"Rose", "Succulent", "Lavender", "Baobab"};
    for (const std::string &plantType: plantTypes) {
        if (message.find(plantType) != std::string::npos) {
            return plantType;
        }
    }

    return "";

}