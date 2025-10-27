
#include "AdvanceTimeCommand.h"
#include <iostream>

AdvanceTimeCommand::AdvanceTimeCommand(int &plantCollection, int numWeeks): plants(plantCollection), weeks(numWeeks ){
    if(weeks < 0) {
        std::cerr << "Warning: Negative weeks not allowed. Setting to 0." << std::endl;
        weeks =0;
    }
}

AdvanceTimeCommand::~AdvanceTimeCommand() {

}

void AdvancedTimeCommand::execute() {
    if(plants.empty()) {
        std::cout << "No plants to age." << std::endl;
        return;
    }

    if(weeks == 0) {
        std::cout << "No time to advance (0 weeks)." << std::endl;
        return;
    }

    std::cout << "\n------ Advancing Time ------" << std::endl;
    std::cout << "Advancing " << weeks << " week(s) for " << plants.size() << "plant (s)..." << std::endl;

    for(int week = 1; week <= weeks; week++) {
        std::cout << "\n--- Week " << week << " ---" << std::endl;

        int agedCount =0;
        int transitionCount =0;

        for (Plant* plant : plants) {
            if(plant != nullptr) {
                std::string previousState= plant->getState();
                plant->grow();
                agedCount++;

                std::string currentState = plant->getState();
                if(currentState != previousState) {
                    transitionCount++;
                    std::cout << " " << plant->getName() << " transitioned: " << previousState << " ->" << currentState << std::endl;
                }
            }else {
                std::cerr << "Warning: Encountered null plant pointer, skipping..." << std::endl;
            }

        }

        std::cout << "Week " << week << " complete: " << agedCount << " plant(s) aged";
        if(transitionCount > 0) {
            std::cout << ", " << transitionCount << " state transition(s)";
        }
        std::cout << std::endl;
    }
    std::cout << "\nTime advancement complete: " << weeks << " week(s) passed." << std::endl;

    std::cout << "============================\n" << std::endl;
}
std::string AdvanceTimeCommand::getDescription() const{
    return "Advance time by " + std::to_string(weeks) + " week(s) for " + std::to_string(plants.size()) + " plants(s)";
}

bool AdvanceTimeCommand::isUndoable() const {
    return false;
}

int AdvanceTimeCommand::getWeeks() const{
    return weeks;
}
void AdvanceTimeCommand::setWeeks(int numWeeks){
    if(numWeeks < 0){
        std::cerr << "Warning: Negative weeks not allowed. Setting to 0." <<std::endl;
        weeks =0;
    }else{
        weeks= numWeeks;
    }
}

int AdvanceTimeCommand::getPlantCount() const{
    return static_cast<int>(plants.size());
}