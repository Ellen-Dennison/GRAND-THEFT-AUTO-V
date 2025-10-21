

#include "RoseFactory.h"
//#include "Rose.h"


Plant* RoseFactory::createPlant() {
    return nullptr; // creating rose with DailyWateringStrategy and seedlingState
}
std::string RoseFactory::getFactoryType() const {
    return "Rose";
}
