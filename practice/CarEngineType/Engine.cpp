#include "Engine.h"
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "m_horsepower: " << rhs.m_horsepower
       << " m_torque: " << rhs.m_torque;
    return os;
}

Engine::Engine(int horsepower, int torque) : m_horsepower{horsepower}, m_torque{torque}{}