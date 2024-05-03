#include "Bike.hpp"


std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << "_bikeId: " << rhs._bikeId
       << " _bikeBrand: " << rhs._bikeBrand
       << " _bikeType: " << static_cast<int>(rhs._bikeType)
       << " _bikePrice: " << rhs._bikePrice
       << " _bikeEngine: " << *rhs._bikeEngine.get().get();
    return os;
}


Bike::Bike(std::string bikeId, std::string bikeBrand, BikeType bikeType, float bikePrice, EnginePointerRef bikeEngine)
    : _bikeId(bikeId), _bikeBrand(bikeBrand), _bikeType(bikeType), _bikePrice(bikePrice), _bikeEngine(bikeEngine) {}



bool Bike::operator<(const Bike &rhs)
{
    return _bikePrice < rhs._bikePrice;
}
