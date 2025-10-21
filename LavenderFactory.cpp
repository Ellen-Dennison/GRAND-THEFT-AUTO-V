
#include "LavenderFactory.h"
//#include "Lavender.h"


Plant* LavenderFactory::createPlant() {
    return nullptr; // creating Lavender with BiWeeklyWateringStrategy and seedlingState
}
std::string LavenderFactory::getFactoryType() const {
    return "Lavender";
}