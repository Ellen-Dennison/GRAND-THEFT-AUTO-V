#include "FlowerFactory.h"
#include <iostream>

FlowerFactory::FlowerFactory(std::string name, double price) 
    : flowerName(name), flowerPrice(price) {
    prototype = new Flower(name, price);
    std::cout << "New "<<name<<" Flower initialised at R"<< price<< std::endl;
}

FlowerFactory::~FlowerFactory() {
    delete prototype;
}

Plant* FlowerFactory::createPlant() {
    std::cout << "Creating " << flowerName << " Flower" << std::endl;
    return prototype->clone();
}

std::string FlowerFactory::getFactoryType() const {
    return "Flower Factory";
}
