#ifndef SUCCULENT_H
#define SUCCULENT_H
#include "Plant.h"


class Succulent:public Plant
{    
    public:
        Succulent(std::string name, std::string type, double price):Plant(name,type,price) {};
        virtual ~Succulent();
        Plant* clone() const;

};

#endif
