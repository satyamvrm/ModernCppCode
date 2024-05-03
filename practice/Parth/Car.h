#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "Engine.h"
#include <memory>

using EngineRef = std::reference_wrapper<Engine>;

class Car
{
private:
    std::string _carId;
    std::string _carBrand;
    CarType _type;
    float _price;
    EngineRef _carEngine;

public:
    Car() = delete;
    Car(Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(Car &) = delete;
    Car &operator=(Car &&) = delete;
    ~Car() = default;

    Car(std::string carId, std::string carBrand, CarType t, float price, EngineRef engine);

    bool operator<(const Car &rhs);

    std::string carId() const { return _carId; }
    void setCarId(const std::string &carId) { _carId = carId; }

    std::string carBrand() const { return _carBrand; }
    void setCarBrand(const std::string &carBrand) { _carBrand = carBrand; }

    CarType type() const { return _type; }
    void setType(const CarType &type) { _type = type; }

    float getPrice() const { return _price; }
    void setPrice(float price) { _price = price; }

    EngineRef carEngine() const { return _carEngine; }
    void setCarEngine(const EngineRef &carEngine) { _carEngine = carEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
