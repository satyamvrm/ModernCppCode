#include "Bike.h"
std::ostream &operator<<(std::ostream &os, const Bike &rhs)
{
    os << "_bikeId: " << rhs._bikeId
       << " _bikeBrand: " << rhs._bikeBrand
       << " _type: " << (rhs._type == BikeType::CLASSIC ? "CLASSIC" : rhs._type == BikeType::LUXURY ? "LUXURY" : "SPORTS")
       << " _price: " << rhs._price <<'\n'
       << " _bikeEngine: " << rhs._bikeEngine.get();
    return os;
}

Bike::Bike(std::string bikeId, std::string bikeBrance, BikeType type, float price, EngineRef engine)
    : _bikeBrand{bikeBrance},
      _bikeId{bikeId},
      _type{type},
      _price{price},
      _bikeEngine{engine}
{
}

bool Bike::operator<(const Bike &rhs)
{
    return _price < rhs._price;
}
