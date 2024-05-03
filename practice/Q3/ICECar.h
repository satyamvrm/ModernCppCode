#ifndef ICECAR_H
#define ICECAR_H

#include "ChassisType.h"
#include "FuelType.h"
#include <ostream>

class ICECar
{
private:
    int _id;
    ChassisType _chassis_type;
    FuelType _fuel_type;
    unsigned int _fuel_tank_capacity;
public:
    ICECar()=default;
    ICECar(const ICECar &)=delete;
    ICECar(ICECar && )=delete;
    ICECar & operator=(const ICECar & )=delete;
    ICECar &operator=(ICECar &&)=delete;
    ~ICECar()=default;
    ICECar(int id, ChassisType chassis_type, FuelType fuel_type, unsigned int fuel_tank_capacity);

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    ChassisType chassisType() const { return _chassis_type; }
    void setChassisType(const ChassisType &chassis_type) { _chassis_type = chassis_type; }

    FuelType fuelType() const { return _fuel_type; }
    void setFuelType(const FuelType &fuel_type) { _fuel_type = fuel_type; }

    unsigned int fuelTankCapacity() const { return _fuel_tank_capacity; }
    void setFuelTankCapacity(unsigned int fuel_tank_capacity) { _fuel_tank_capacity = fuel_tank_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_H
