#include "Engine.h"

std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "_horsePower: " << rhs._horsePower
       << " _torque: " << rhs._torque;
    return os;
}

Engine::Engine(int horsePower, float torque)
    : _horsePower{horsePower}, _torque{torque} {}
