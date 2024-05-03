#include "Car.h"

Car::Car(int p, int y)
    : _price{p}, _launchYear{y}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_price: " << rhs._price
       << " _launchYear: " << rhs._launchYear;
    return os;
}
