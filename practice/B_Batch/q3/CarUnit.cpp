#include "CarUnit.h"
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs)
{
    os << "_brand: " << rhs._brand
       << " _price: " << rhs._price
       << " _type: " << displayEnum(rhs._type)
       << " _topSpeed: " << rhs._topSpeed
       << " _top_rpm: " << rhs._top_rpm
       << " _gear: " << displayEnum(rhs._gear);
    return os;
}

std::string displayEnum(CarGear t)
{
    if (t == CarGear::CLASSIC)
        return "CLASSIC";
    else if (t == CarGear::PRNDL)
        return "PRNDL";
    else if (t == CarGear::TIPTRONIC)
        return "TIPTRONIC";
    else
        return "";
}

std::string displayEnum(CarType t)
{
    if (t == CarType::HATCHBACK)
        return "HATCHBACK";
    else if (t == CarType::SEDAN)
        return "SEDAN";
    else
        return "SUV";
}

CarUnit::CarUnit(std::string brand, float price, CarType type, unsigned int topSpeed, unsigned int top_rpm, CarGear gear)
    : _brand{brand},
      _price{price},
      _type{type},
      _topSpeed{topSpeed}, _top_rpm{top_rpm}, _gear{gear}
{
}