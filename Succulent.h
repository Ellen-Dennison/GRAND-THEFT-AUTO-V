#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"
//#include "WateringStrategy.h"
//#include "Enums.h"

class Succulent : public Plant {
public:
    Succulent(std::string name, double price);
    virtual ~Succulent() {};
    Plant* clone() const override;
};

#endif
