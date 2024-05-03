#include "Bike.h"

std::string displayType(BrakingSystem t){
    if(t==BrakingSystem::TRADITIONAL) return "Traditional";
    else return "ABS";
}

std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _braking_system: " << displayType(rhs._braking_system);
    return os;
}

Bike::Bike(std::string id, std::string name, float price, BrakingSystem type)
    : Vehicle(id,name,price), _braking_system(type)
{}

float Bike::CalculateServicingCost()
{
    return (price()*0.25)+(price()*0.25)*0.18;
}
