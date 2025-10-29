#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include<iostream>
#include<string>

class Plant;

class WateringStrategy{
    public:
    virtual ~WateringStrategy(){};
    virtual void water(Plant* plant) = 0;
    virtual std::string getWateringSchedule() const = 0;
};

#endif
