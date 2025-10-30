#include "TreeFactory.h"
#include <iostream>

TreeFactory::TreeFactory(std::string name, double price) 
    : treeName(name), treePrice(price) {
    prototype = new Tree(name, price);
    std::cout<<"New "<<name<<" Tree initialised at R"<< price << std::endl;
}

TreeFactory::~TreeFactory() {
    delete prototype;
}

Plant* TreeFactory::createPlant() {
    std::cout << "Creating " << treeName << " Tree"<< std::endl;
    return prototype->clone();
}

std::string TreeFactory::getFactoryType() const {
    return "Tree Factory";
}
