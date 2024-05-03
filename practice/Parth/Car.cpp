#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_carId: " << rhs._carId
       << " _carBrand: " << rhs._carBrand
       << " _type: " << ((rhs._type == CarType::HATCHBACK) ? "HATCHBACK" : (rhs._type == CarType::SEDAN) ? "SEDAN": "SUV");
    os << " _price: " << rhs._price<<'\n'
       << " _carEngine: " << rhs._carEngine.get();
    return os;
}

Car::Car(std::string carId, std::string carBrand, CarType t, float price, EngineRef engine)
    : _carId{carId}, _carBrand{carBrand}, _type{t}, _price{price}, _carEngine{engine}
{
}

bool Car::operator<(const Car &rhs)
{
    return _price < rhs._price;
}
