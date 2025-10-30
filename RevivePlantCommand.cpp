
#include "RevivePlantCommand.h"
#include <iostream>

RevivePlantCommand::RevivePlantCommand(Plant* targetPlant, PlantCaretaker* plantCaretaker, const std::string& id) : plant(targetPlant), caretaker(plantCaretaker), plantIdentifier(id){
    if(plant == nullptr){
        std::cerr << "Warning: RevivePlantCommand created with null plant pointer" << std::endl;
    }
    if(caretaker == nullptr){
        std::cerr << "Warning: RevivePlantCommand created with null caretaker pointer" << std::endl;
    }

    if(plantIdentifier.empty()) {
        std::cerr << "Warning: RevivePlantCommand created with empty plant ID" << std::endl;
    }
}


RevivePlantCommand::~RevivePlantCommand(){

}
void RevivePlantCommand::execute() {

    std::cout << "\n------ Plant Revival Operation ------" << std::endl;
    std::cout <<" Attempting to revive plant: " << plantIdentifier<< std::endl;

    if (plant == nullptr) {
        std::cerr << "Error: Plant pointer is null. Cannot revive."  << std::endl;
        std::cout << "Revival failed.\n" << std::endl;
        return;
    }

    if (caretaker == nullptr) {
        std::cerr << "Error: Caretaker pointer is null. Cannot access saved states."  << std::endl;
        std::cout << "Revival failed.\n" << std::endl;
        return;
    }

    std::string currentState = plant->getStateName();
    std::cout << "Current plant state: " << currentState << std::endl;

    if (currentState == "Dead") {
        std::cout << "Plant is dead. Revival is impossible (point of no return)."  << std::endl;
        std::cout << "Revival failed.\n" << std::endl;
        return;
    }

    if (currentState != "Wilting") {
        std::cout << "Plant is not wilting (current state: " << currentState << ")."  << std::endl;
        std::cout << "No revival needed - plant is healthy.\n" << std::endl;
        return;
    }

    std::cout << "Plant is wilting. Searching for saved state..." << std::endl;

    PlantMemento* memento = caretaker->getMemento(plantIdentifier);
    if (memento == nullptr) {
        std::cerr << "Error: No saved state found for plant " << plantIdentifier << std::endl;
        std::cout << "Cannot revive without a backup state." << std::endl;
        std::cout << "Revival failed.\n" << std::endl;
        return;
    }

    std::cout << "\nSaved state found:" << std::endl;
    std::cout << " Saved State: " << memento->getStateName() << std::endl;
    std::cout << " Saved Health: " << memento->getHealthLevel() << "%" << std::endl;
    std::cout << " Saved Age: " << memento->getAge() << "weeks"<< std::endl;


    std::cout << "\nRestoring plant from saved state..." << std::endl;

    int previousHealth = plant->getHealthLevel();
    plant->restoreFromMemento(memento);

    std::string restoredState = plant->getState();
    int restoredHealth = plant->getHealthLevel();

    std:: cout << "\nRestoration complete:" << std::endl;
    std::cout << " State: Wilting -> " << restoredState << std::endl;
    std::cout << " Health: " << previousHealth << "% -> " << restoredHealth << "%" << std::endl;

    std::cout << "\n✔ Plant " << plantIdentifier << " successfully revived!" << std::endl;

    std::cout << "=======================================\n" << std::endl;

}


std::string RevivePlantCommand::getDescription() const {
    return "Revive plant " + plantIdentifier + " from saved state";
}

bool RevivePlantCommand::isUndoable() const {
    return false;
}
std::string RevivePlantCommand::getPlant() const{
    return  plantIdentifier;
}

bool RevivePlantCommand::canRevive() const{
    if(plant == nullptr){
        return false;
    }

    if(caretaker == nullptr){
        return false;
    }

    std::string currentState = plant->getState();
    if(currentState != "Wilting") {
        return false;
    }

    if(!caretaker->hasMemento(plantIdentifier)) {
        return false;
    }
    return true;
}
