#include "Car.h"

std::string displayCar(CarType t){
    if(CarType::Hatchback==t) return "Hatchback";
    else if (t==CarType::Sedan) return "Sedan";
    else return "SUV";
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _carType: " << displayCar(rhs._carType)
       << " _carPrice: " << rhs._carPrice
       << " carColour: " << rhs._carColour;
    return os;
}

Car::Car(std::variant<int, std::string> id, int reg, VehicleType vtype, std::reference_wrapper<Insurance> insurance, CarType ctype, float price, std::string colour)
    : Vehicle(id,reg,vtype,insurance)
{
    _carType = ctype;
    _carPrice = price;
    _carColour = colour;
}