#include "Car.hpp"


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_carId: " << rhs._carId
       << " _carBrand: " << rhs._carBrand
       << " _carType: " << static_cast<int>(rhs._carType)
       << " _carPrice: " << rhs._carPrice
       << " _carEngine: " << *rhs._carEngine.get().get();
    return os;
}


Car::Car(std::string carId, std::string carBrand, CarType carType, float carPrice, EnginePointerRef carEngine)
    : _carId(carId), _carBrand(carBrand), _carType(carType), _carPrice(carPrice), _carEngine(carEngine) {}


bool Car::operator<(const Car &rhs)
{
    return _carPrice < rhs._carPrice;
}
