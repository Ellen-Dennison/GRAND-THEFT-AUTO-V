

#include "BaobabFactory.h"
//#include "Baobab.h"


Plant* BaobabFactory::createPlant() {
    return nullptr; // creating succulent with BiWeeklyWateringStrategy and seedlingState
}
std::string BaobabFactory::getFactoryType() const {
    return "Baobab";
}