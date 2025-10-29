#include "Tree.h"

Plant* Tree::clone() const
{ return new Tree(*this); }

Tree::~Tree()
{}