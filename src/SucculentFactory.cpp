#include "SucculentFactory.h"
#include <iostream>

SucculentFactory::SucculentFactory(std::string name, double price) 
    : succulentName(name), succulentPrice(price) {
    prototype = new Succulent(name, price);
    std::cout << "New " << name << " Succulent initialised at R"<< price  << std::endl;
}

SucculentFactory::~SucculentFactory() {
    delete prototype;
}

Plant* SucculentFactory::createPlant() {
    std::cout << "Creating " << succulentName << " Succulent"<< std::endl;
    return prototype->clone();
}

std::string SucculentFactory::getFactoryType() const {
    return "Succulent Factory";
}
