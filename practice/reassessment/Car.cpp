#include "Car.h"

Car* Car::_solo_object{ nullptr};

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_model: " << rhs._model
       << " _year_of_manufacturing: " << rhs._year_of_manufacturing
       << " _Ctype: " << displayEnum(rhs._Ctype);
    return os;
}

std::string displayEnum(CarType t)
{
    if(t==CarType::HATCHBACK) return "Hatchback";
    else if(t==CarType::SEDAN) return "Sedan";
    else return "SUV";
}
