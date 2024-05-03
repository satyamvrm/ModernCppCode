#include "Car.h"

std::string displayType(CarType t){
    if(t==CarType::COMMERCIAL) return "COMMERCIAL";
    else if(t==CarType::COMMUTE) return "COMMUTE";
    else return "TRANSPORT";
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _car_type: " << displayType(rhs._car_type);
    return os;
}

Car::Car(std::string regId, std::string name, float price, CarType type)
    : Vehicle(regId, name, price), _car_type{type}
{}

float Car::CalculateServicingCost()
{
    return price()*0.08;
}

float Car::TaxExemptionAmount()
{
    if(_car_type == CarType::COMMUTE) return price()*0.2;
    else return price()*0.15;
}
