#include "ICECar.h"
std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id
       << " _fuel_tank_capacity: " << rhs._fuel_tank_capacity;
    return os;
}

ICECar::ICECar(int id, ChassisType chassis_type, FuelType fuel_type, unsigned int fuel_tank_capacity)
        : _id{id}, _chassis_type{chassis_type}, _fuel_type{fuel_type}, _fuel_tank_capacity{fuel_tank_capacity} {}