#include "ICECar.h"
std::ostream &operator<<(std::ostream &os, const ICECar &rhs)
{
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: " << displayEnum(rhs._engine_type);
    return os;
}

std::string displayEnum(EngineType t)
{
    if (t == EngineType::DIESEL)
        return "DIESEL";
    else
        return "PETROL";
}

ICECar::ICECar(std::string id, std::string bname, float price, EngineType etype)
    : _id{id}, _brand_name{bname}, _price{price}, _engine_type{etype}
{
}

float ICECar::CalculateRegistrationCharge()
{
    if (_engine_type == EngineType::DIESEL)
        return _price * 0.13;
    else
        return _price * 0.1;
}
