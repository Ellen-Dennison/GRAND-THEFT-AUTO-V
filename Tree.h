#ifndef TREE_H
#define TREE_H
#include "Plant.h"


class Tree:public Plant
{
    public:
    Tree(std::string name, std::string type, double price):Plant(name,type,price)
    {};//!CHANGES
    virtual ~Tree();//!CHANGES
    Plant* clone() const;

};

#endif
