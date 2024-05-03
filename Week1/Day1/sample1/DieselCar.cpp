#include "DieselCar.h"


DieselCar::DieselCar(int fule, float milage) : _fuelCapacity{fule}, _milage{milage}
{
}

std::ostream &operator<<(std::ostream &os, const DieselCar &rhs) {
    os << static_cast<const Car &>(rhs)
       << " _fuelCapacity: " << rhs._fuelCapacity
       << " _milage: " << rhs._milage;
    return os;
}

float DieselCar::Drive()
{
    return _milage;
}


