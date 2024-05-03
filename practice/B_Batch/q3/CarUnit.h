#ifndef CARUNIT_H
#define CARUNIT_H

#include "CarType.h"
#include "CarGear.h"
#include <iostream>

class CarUnit
{
private:
    /* data */
    std::string _brand;
    float _price;
    CarType _type;
    unsigned int _topSpeed;
    unsigned int _top_rpm;
    CarGear _gear;

public:
    CarUnit() = delete;
    CarUnit(CarUnit &) = delete;
    CarUnit(CarUnit &&) = delete;
    CarUnit &operator=(CarUnit &) = delete;
    CarUnit &operator=(CarUnit &&) = delete;
    ~CarUnit() = default;

    CarUnit(
        std::string brand, float price, CarType type, unsigned int topSpeed, unsigned int top_rpm, CarGear gear);

    std::string brand() const { return _brand; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    CarType type() const { return _type; }
    void setType(const CarType &type) { _type = type; }

    unsigned int topSpeed() const { return _topSpeed; }
    void setTopSpeed(unsigned int topSpeed) { _topSpeed = topSpeed; }

    unsigned int topRpm() const { return _top_rpm; }
    void setTopRpm(unsigned int top_rpm) { _top_rpm = top_rpm; }

    CarGear gear() const { return _gear; }
    void setGear(const CarGear &gear) { _gear = gear; }

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};
std::string displayEnum(CarGear t);
std::string displayEnum(CarType t);

#endif // CARUNIT_H
