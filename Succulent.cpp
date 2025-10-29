#include "Succulent.h"

Plant* Succulent::clone() const
{ return new Succulent(*this); }

Succulent::~Succulent()
{}