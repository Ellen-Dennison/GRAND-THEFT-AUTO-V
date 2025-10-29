#ifndef HERB_H
#define HERB_H
#include "Plant.h"


class Herb:public Plant
{
    public:
        Herb(std::string name, std::string type, double price):Plant(name,type,price) {};
        virtual ~Herb();
        Plant* clone() const;
};

#endif
