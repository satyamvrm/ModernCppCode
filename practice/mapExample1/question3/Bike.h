#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"
#include "BreakingSystem.h"
#include <ostream>

class Bike : public Vehicle 
{
private:
    BrakingSystem _braking_system;

public:
    //default constructor disabled
    Bike()=delete;
    //default copy constructor disabled
    Bike(const Bike&) = default;
    // default move constructor disabled 
    Bike( Bike&&) = default;
    // default assignment operator disabled 
    Bike &operator=(const Bike&) = default; 
    // default move operator disabled
    Bike &operator=( Bike&&) = default; 
    // default distructor enabled 
    ~Bike()=default;

    Bike(std::string id, std::string name, float price, BrakingSystem type);

    float CalculateServicingCost();

    BrakingSystem brakingSystem() const { return _braking_system; }
    void setBrakingSystem(const BrakingSystem &braking_system) { _braking_system = braking_system; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);


};

#endif // BIKE_H
