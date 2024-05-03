#include "EvCar.h"
std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: " << displayEnum(rhs._engine_type)
       << " _battery_type: " << displayEnum(rhs._battery_type);
    return os;
}

std::string displayEnum(BatteryType t)
{
    if (t == BatteryType::LI_ION)
        return "LI_ION";
    else if (t == BatteryType::NI_CAD)
        return "NI_CAD";
    else
        return "OTHER";
}

std::string displayEnum(EPowerType t)
{
    if (t == EPowerType::ELECTIC)
        return "ELECTIC";
    else
        return "HYBRID";
}

EvCar::EvCar(std::string id, std::string bname, float price, EPowerType etype, BatteryType b)
    : _id{id}, _brand_name{bname}, _price{price}, _engine_type{etype}, _battery_type{b}
{
}

float EvCar::CalculateRegistrationCharge()
{
    if (_engine_type == EPowerType::ELECTIC)
        return _price * 0.05;
    else
        return _price * 0.08;
}
