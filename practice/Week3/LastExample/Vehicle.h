#ifndef VEHICLE_H
#define VEHICLE_H

#include "VehicleType.h"
#include "Insurance.h"
#include<variant>
#include<memory>
#include <ostream>

class Vehicle
{
private:
    std::variant<int,std::string> _registrationId;
    int _reistrationNo;
    VehicleType _type;
    std::reference_wrapper<Insurance> _insurance;

public:
    //default constructor disabled
    Vehicle()=delete;
    //default copy constructor disabled
    Vehicle(const Vehicle&) = delete;
    // default move constructor disabled 
    Vehicle(const Vehicle&&) = delete;
    // default assignment operator disabled 
    Vehicle &operator=(const Vehicle&) = delete; 
    // default move operator disabled
    Vehicle &operator=(const Vehicle&&) = delete; 
    // default distructor enabled 
    ~Vehicle()=default;

    std::variant<int,std::string> registrationId() const { return _registrationId; }
    void setRegistrationId(const std::variant<int,std::string> &registrationId) { _registrationId = registrationId; }

    int reistrationNo() const { return _reistrationNo; }
    void setReistrationNo(int reistrationNo) { _reistrationNo = reistrationNo; }

    VehicleType type() const { return _type; }
    void setType(const VehicleType &type) { _type = type; }

    std::reference_wrapper<Insurance> insurance() const { return _insurance; }
    void setInsurance(const std::reference_wrapper<Insurance> &insurance) { _insurance = insurance; }

    Vehicle(std::variant<int,std::string> id, int reg, VehicleType type, std::reference_wrapper<Insurance> insurance);

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

    
};
std::string displayVehicle(VehicleType t);
#endif // VEHICLE_H
