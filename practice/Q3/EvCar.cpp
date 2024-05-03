#include "EvCar.h"

EvCar::EvCar(int id, ChassisType chassis_type, BatteryType battery_type, float battery_capacity)
    : _id{id}, _chassis_type{chassis_type}, _battery_type{battery_type}, _battery_capacity{battery_capacity} {}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << "_id: " << rhs._id
       << " _battery_capacity: " << rhs._battery_capacity;
    return os;
}
