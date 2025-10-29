#include "Flower.h"

Plant *Flower::clone() const
{ return new Flower(*this); }

Flower::~Flower()
{}