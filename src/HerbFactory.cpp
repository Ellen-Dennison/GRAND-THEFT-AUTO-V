#include "HerbFactory.h"
#include <iostream>

HerbFactory::HerbFactory(std::string name, double price) 
    : herbName(name), herbPrice(price) {
    prototype = new Herb(name, price);
    std::cout << "New " << name << " Herb initialised at R"<< price << std::endl;
}

HerbFactory::~HerbFactory() {
    delete prototype;
}

Plant* HerbFactory::createPlant() {
    std::cout << "Creating " << herbName<<" herb"<<std::endl;
    return prototype->clone();
}

std::string HerbFactory::getFactoryType() const {
    return "Herb Factory";
}
