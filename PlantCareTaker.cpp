

#include "PlantCareTaker.h"
#include <iostream>

PlantCaretaker::PlantCaretaker() {

}

PlantCaretaker::~PlantCaretaker() {
    for(auto& pair : mementos) {
        delete pair.second;
        pair.second = nullptr;
    }
    mementos.clear();
}

void PlantCaretaker::saveMemento(const std::string &plantId, PlantMemento *memento) {
    if(plantId.empty()) {
        std::cerr << "Error: Cannot save memento with empty plant ID"  << std::endl;
        return;
    }

    if(memento == nullptr) {
        std::cerr << "Error: Cannot save null memento for plant " << plantId << std::endl;
        return;
    }
    auto it = mementos.find(plantId);
    if(it != mementos.end()){
        delete it->second;
        std::cout << "Updated existing memento for plant: "  plantId << std::endl;
    }
    mementos[plantId] = memento;
}

PlantMemento* PlantCaretaker::getMemento(const std::string &plantId) const {
    if(plantId.empty()) {
        std::cerr << "Error: Cannot retrieve memento with empty plant ID"  << std::endl;
        return nullptr;

        auto it =  mementos.find(plantId);
        if(it != mementos.end()){
            return  it->second;
        }else{
            std::cerr << "Warning: No memento found for plant " << plantId << std::endl;
            return nullptr;
        }
    }

    bool PlantCaretaker::hasMemento(const std::string &plantId) const {
        if(plantId.empty()){
            return false;
        }
        return mementos.find(plantId) != mementos.end();
    }
}


bool PlantCaretaker::deleteMemento(const std::string &plantId) {
    if(plantId.empty()) {
        std::cerr << "Error: Cannot delete memento with empty plant ID"  << std::endl;
        return false;
    }

    auto it =mementos.find(plantId);

    if(it != mementos.end()){
        delete it->second;
        mementos.erase(it);
        std::cout << "Deleted memento for plant: " << plantId << std::endl;
        return true;
    }else {
        std::cerr << "Warning: No memento found to delete for plant " << plantId << std::endl;
        return false;
    }
}

int PlantCaretaker::getMementoCount() const {
    return static_cast<int>(mementos.size());
}

void PlantCaretaker::clearAllMementos() {
    for(auto& pair : mementos) {
        delete pair.second;
        pair.second = nullptr;
    }
    mementos.clear();

    std::cout << "All mementos cleared from caretaker" << std::endl;
}

void PlantCaretaker::displayAllMementos() const {
    std::cout << "\n------ Stored Mementos ------" << std::endl;
    std::cout << "Total mementos: " << mementos.size() << std::endl;

    if (mementos.empty()) {
        std::cout << "No mementos currently stored." << std::endl;
    } else {
        std::cout << "\nPlant States:" << std::endl;
        std::cout << "------------------------------------------" << std::endl;

        for (const auto &pair: mementos) {

            std::cout << "Plant ID: " << pair.first << std::endl;
            std::cout << "State: " << pair.second->getState() << std::endl;
            std::cout << "Age: " << pair.second->getAge() << " weeks"
            std::endl;
            std::cout << "Health: " << pair.second->getHealthLevel() << "%"
            std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }
    std::cout << "========================================\n" << std::endl;
}