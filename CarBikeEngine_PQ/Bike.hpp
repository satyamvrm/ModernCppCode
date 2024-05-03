#ifndef BIKE_HPP
#define BIKE_HPP

#include<memory>
#include <ostream>
#include"Engine.hpp"
#include"BikeType.hpp"
#include"Car.hpp"

class Bike
{
private:
    std::string _bikeId;
    std::string _bikeBrand;
    BikeType _bikeType;
    float _bikePrice;
    EnginePointerRef _bikeEngine;

public:
    Bike() = delete;
    Bike(const Bike&&) = delete;
    Bike(Bike&&) = delete;
    Bike& operator=(const Bike&) = delete;
    Bike& operator=(Bike&&) = delete;
    ~Bike() = default;

    Bike(std::string bikeId, std::string bikeBrand, BikeType bikeType, float bikePrice, EnginePointerRef bikeEngine);

    std::string bikeId() const { return _bikeId; }
    std::string bikeBrand() const { return _bikeBrand; }
    BikeType bikeType() const { return _bikeType; }
    float bikePrice() const { return _bikePrice; }
    EnginePointerRef bikeEngine() const { return _bikeEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);

    bool operator<(const Bike& rhs);

};


#endif // BIKE_HPP
