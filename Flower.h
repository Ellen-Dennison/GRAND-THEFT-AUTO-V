#ifndef FLOWER_H
#define FLOWER_H
#include "Plant.h"


class Flower:public Plant
{
    public:
        Flower(std::string name, std::string type, double price):Plant(name,type,price) {};
        virtual ~Flower();
        Plant* clone() const;
};

#endif
