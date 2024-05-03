#include "EvCar.h"

EvCar::EvCar(std::string car_id, unsigned int battery_charging_time, Platform platform, float chassis_length, unsigned int seat_count, unsigned int top_speed)
    : m_car_id{car_id},
      m_battery_charging_time{battery_charging_time},
      m_platform{platform},
      m_chassis_length{chassis_length},
      m_seat_count{seat_count},
      m_top_speed{top_speed}
{
}
std::ostream &operator<<(std::ostream &os, const EvCar &rhs)
{
    os << "m_car_id: " << rhs.m_car_id
       << " m_battery_charging_time: " << rhs.m_battery_charging_time
       << " m_platform: " << displayEnum(rhs.m_platform)
       << " m_chassis_length: " << rhs.m_chassis_length
       << " m_seat_count: " << rhs.m_seat_count
       << " m_top_speed: " << rhs.m_top_speed;
    return os;
}

std::string displayEnum(Platform t)
{
    if (t == Platform::IC_BASED)
        return "IC_BASED";
    else
        return "EV_BASED";
}
