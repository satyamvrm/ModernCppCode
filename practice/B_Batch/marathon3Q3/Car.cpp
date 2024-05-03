#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_seatCount: " << rhs._seatCount
       << " _price: " << rhs._price
       << " _wheelBase: " << rhs._wheelBase
       << " _ctype: " << displayEnum(rhs._ctype);
    return os;
}

std::string displayEnum(ChassisType t)
{
    if (t == ChassisType::CARBON_FIBER)
        return "CARBON_FIBER";
    else
        return "STEEL";
}

Car::Car(int seatcount, float price, float wheel, ChassisType ctype)
    : _seatCount{seatcount},
      _price{price},
      _wheelBase{wheel},
      _ctype{ctype}
{
}
