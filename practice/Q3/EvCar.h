#ifndef EVCAR_H
#define EVCAR_H

#include "ChassisType.h"
#include "BatteryType.h"
#include <iostream>

class EvCar
{
private:
    int _id;
    ChassisType _chassis_type;
    BatteryType _battery_type;
    float _battery_capacity;
public:
    EvCar()=default;
    EvCar(const EvCar &)=delete;
    EvCar(EvCar && )=delete;
    EvCar & operator=(const EvCar & )=delete;
    EvCar &operator=(EvCar &&)=delete;
    ~EvCar()=default;
    EvCar(int id, ChassisType chassis_type, BatteryType battery_type, float battery_capacity);

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    BatteryType batteryType() const { return _battery_type; }
    void setBatteryType(const BatteryType &battery_type) { _battery_type = battery_type; }

    ChassisType chassisType() const { return _chassis_type; }
    void setChassisType(const ChassisType &chassis_type) { _chassis_type = chassis_type; }

    float batteryCapacity() const { return _battery_capacity; }
    void setBatteryCapacity(float battery_capacity) { _battery_capacity = battery_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
