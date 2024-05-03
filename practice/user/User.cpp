#include "User.h"
std::ostream &operator<<(std::ostream &os, const User &rhs) {
    os << "_name: " << rhs._name
       << " _age: " << rhs._age
       << " _income: " << rhs._income;
    return os;
}

User::User(std::string name, int age, float income)
    : _name{name}, _age{age}, _income{income}
{}

float User::operator+(const User &rhs)
{
    return rhs.income()+income();
}