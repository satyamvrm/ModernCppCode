#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_registration_number: " << rhs._registration_number
       << " _brand: " << rhs._brand
       << " _price: " << rhs._price;
    return os;
}

Vehicle::Vehicle(std::string regNo, std::string name, float price)
    : _registration_number{regNo}, _brand{name}, _price{price}
{}

float Vehicle::TaxExemptionAmount()
{
    return _price*0.05;
}
