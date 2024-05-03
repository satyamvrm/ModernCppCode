#include "Vehicle.h"
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
{
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _vCategory: " << displayEnum(rhs._vCategory)
       << " _type: " << displayEnum(rhs._type)
       << " _bootSpace: " << rhs._bootSpace
       << " _insured: " << std::boolalpha << rhs._insured;
    return os;
}

Vehicle::Vehicle(std::string id, float price, Category vCategory, TransmissionType type, unsigned int bootSpace, bool insured)
    : _id{id},
      _price{price},
      _vCategory{vCategory},
      _type{type},
      _bootSpace{bootSpace},
      _insured{insured}
{
}

std::string displayEnum(Category t)
{
    return t == Category::PRIVATE ? "PRIVATE" : t == Category::PUBLIC ? "PUBLIC"
                                                                      : "GOVT";
}

std::string displayEnum(TransmissionType t)
{
    return t == TransmissionType::AUTOMATIC ? "AUTOMATIC" : t == TransmissionType::MANUAl ? "MANUAl"
                                                                                          : "AMT";
}
