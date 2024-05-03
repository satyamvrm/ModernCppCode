#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "BikeType.h"
#include "Engine.h"
#include <memory>

using EngineRef = std::reference_wrapper<Engine>;

class Bike
{
private:
    /* data */
    std::string _bikeId;
    std::string _bikeBrand;
    BikeType _type;
    float _price;
    EngineRef _bikeEngine;

public:
    Bike() = delete;
    Bike(Bike &) = delete;
    Bike(Bike &&) = delete;
    Bike &operator=(Bike &) = delete;
    Bike &operator=(Bike &&) = delete;
    ~Bike() = default;


    Bike(std::string bikeId, std::string bikeBrance, BikeType type, float price, EngineRef engine);

    bool operator<(const Bike& rhs);

    std::string bikeId() const { return _bikeId; }

    std::string bikeBrand() const { return _bikeBrand; }

    BikeType type() const { return _type; }

    float getPrice() const { return _price; }

    EngineRef bikeEngine() const { return _bikeEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
