#include "Vehicle.h"

Vehicle::Vehicle(std::string id, float price, VehicleCategory category, TransmissionType type, unsigned int bootSpace, bool isInsured)
    : _id{id}, _price{price}, _category{category}, _type{type}, _bootSpace{bootSpace}, _isInsured{isInsured}
{
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
{
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _category: " << displayEnum(rhs._category)
       << " _type: " << displayEnum(rhs._type)
       << " _bootSpace: " << rhs._bootSpace
       << " _isInsured: " << std::boolalpha << rhs._isInsured;
    return os;
}

std::string displayEnum(VehicleCategory t)
{
    if (t == VehicleCategory::GOVERNMENT)
        return "GOVERNMENT";
    else if (t == VehicleCategory::PRIVATE)
        return "PRIVATE";
    else
        return "PUBLIC";
}

std::string displayEnum(TransmissionType t)
{
    if (t == TransmissionType::AMT)
        return "AMT";
    else if (t == TransmissionType::AUTOMATC)
        return "AUTOMATC";
    else
        return "MANUAL";
}
