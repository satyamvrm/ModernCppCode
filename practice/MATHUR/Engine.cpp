#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "hp: " << rhs.hp
       << " cc: " << rhs.cc;
    return os;
}
