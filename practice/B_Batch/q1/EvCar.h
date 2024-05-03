#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include <string>
#include "Platform.h"

class EvCar
{
private:
    /* data */
    std::string m_car_id;
    unsigned int m_battery_charging_time;
    Platform m_platform;
    float m_chassis_length;
    unsigned int m_seat_count;
    unsigned int m_top_speed;

public:
    EvCar() = delete;
    EvCar(const EvCar &) = delete;
    EvCar &operator=(const EvCar &) = delete;
    EvCar(EvCar &&) = delete;
    EvCar &operator=(EvCar &&) = delete;
    ~EvCar() = default;

    EvCar(std::string car_id, unsigned int battery_charging_time, Platform platform, float chassis_length, unsigned int seat_count, unsigned int top_speed);
    
    std::string carId() const { return m_car_id; }
    void setCarId(const std::string &car_id) { m_car_id = car_id; }

    unsigned int batteryChargingTime() const { return m_battery_charging_time; }
    void setBatteryChargingTime(unsigned int battery_charging_time) { m_battery_charging_time = battery_charging_time; }

    Platform platform() const { return m_platform; }
    void setPlatform(const Platform &platform) { m_platform = platform; }

    float chassisLength() const { return m_chassis_length; }
    void setChassisLength(float chassis_length) { m_chassis_length = chassis_length; }

    unsigned int seatCount() const { return m_seat_count; }
    void setSeatCount(unsigned int seat_count) { m_seat_count = seat_count; }

    unsigned int topSpeed() const { return m_top_speed; }
    void setTopSpeed(unsigned int top_speed) { m_top_speed = top_speed; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};
std::string displayEnum(Platform t);
#endif // EVCAR_H
