#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _topSpeed: " << rhs._topSpeed
       << " _xShowRoomPrice: " << rhs._xShowRoomPrice;
    return os;
}

Car::Car(std::string name, int acceleration, int topSpeed, float price)
    : _name{name}, _acceleration{acceleration}, _topSpeed{topSpeed}, _xShowRoomPrice{price} {}
