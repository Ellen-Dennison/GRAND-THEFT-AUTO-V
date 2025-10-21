
#include "SucculentFactory.h"
//#include "Succulent.h"


Plant* SucculentFactory::createPlant() {
    return nullptr; // creating succulent with WeeklyWateringStrategy and seedlingState
}
std::string SucculentFactory::getFactoryType() const {
    return "Succulent";
}
