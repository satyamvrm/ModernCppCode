#ifndef CAR_HPP
#define CAR_HPP

#include<memory>
#include <ostream>
#include"Engine.hpp"
#include"CarType.hpp"

using EnginePointerRef = std::reference_wrapper<std::shared_ptr<Engine>>;

class Car
{
private:
    std::string _carId;
    std::string _carBrand;
    CarType _carType;
    float _carPrice;
    EnginePointerRef _carEngine;

public:
    Car() = delete;
    Car(const Car&&) = delete;
    Car(Car&&) = delete;
    Car& operator=(const Car&) = delete;
    Car& operator=(Car&&) = delete;
    ~Car() = default;

    Car(std::string carId, std::string carBrand, CarType carType, float carPrice, EnginePointerRef carEngine);

    std::string carId() const { return _carId; }
    std::string carBrand() const { return _carBrand; }
    CarType carType() const { return _carType; }
    float carPrice() const { return _carPrice; }
    EnginePointerRef carEngine() const { return _carEngine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    bool operator<(const Car& rhs);

};

#endif // CAR_HPP
