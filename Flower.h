#ifndef FLOWER_H
#define FLOWER_H
#include "Plant.h"
//#include "WateringStrategy.h"
//#include "Enums.h"


class Flower: public Plant
{
    public:
        Flower(std::string name, double price);
        virtual ~Flower() {}; //Not needed
        Plant* clone() const override;
};

#endif
