#include "Brand.h"

Brand::Brand(std::string name, CarArray cars)
    : _name{name}, _cars{cars}
{
}
std::ostream &operator<<(std::ostream &os, const Brand &rhs)
{
    os << "_name: " << rhs._name
       << "\n _cars: ";
    for (auto a : rhs._cars)
        os << '\n' << *a.get();
    return os;
}
