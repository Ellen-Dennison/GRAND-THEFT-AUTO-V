#include "Herb.h"

Plant *Herb::clone() const
{ return new Herb(*this); }

Herb::~Herb()
{}