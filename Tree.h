#ifndef TREE_H
#define TREE_H
#include "Plant.h"


class Tree:public Plant
{
    public:
    Tree(std::string name, std::string type, double price,std::string plant):Plant(name,type,price,plant)
    {};//!CHANGES
    //void setPlant(std::string plant);
};

#endif
