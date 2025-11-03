#ifndef TREE_H
#define TREE_H

#include "Plant.h"
#include "WateringStrategy.h"
#include "Enums.h"

class Tree : public Plant {
public:
    Tree(std::string name, double price);
    Plant* clone() const override;
};

#endif
