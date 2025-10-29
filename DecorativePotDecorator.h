#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H
#include "PlantDecorator.h"

class DecorativePotDecorator:public PlantDecorator
{   
   private:
   double price;
    
   public:
        DecorativePotDecorator(Plant* plant);
        virtual double getPrice();
        virtual void display();
        virtual Plant* clone() const;
   
};

#endif