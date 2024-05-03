#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "ChassisType.h"

class Car
{
private:
    /* data */
    int _seatCount;
    float _price;
    float _wheelBase;
    ChassisType _ctype;

public:
    Car() = delete;
    Car(const Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(const Car &) = delete;
    Car &operator=(Car &&) = delete;
    ~Car() = default;

    Car(int seatcount, float price, float wheel, ChassisType ctype);

    int seatCount() const { return _seatCount; }
    void setSeatCount(int seatCount) { _seatCount = seatCount; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    float wheelBase() const { return _wheelBase; }
    void setWheelBase(float wheelBase) { _wheelBase = wheelBase; }

    ChassisType ctype() const { return _ctype; }
    void setCtype(const ChassisType &ctype) { _ctype = ctype; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};
std::string displayEnum(ChassisType t);
#endif // CAR_H
