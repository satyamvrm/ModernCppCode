#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include <memory>
#include <ostream>

class Car
{
private:
    /* data */
    std::string _car_reg_num;
    float _price;
    std::reference_wrapper<Engine> _car_engine;

public:
    Car() = delete;
    Car(Car &) = delete;
    Car(Car &&) = delete;
    Car &operator=(Car &) = delete;
    Car &operator=(Car &&) = delete;
    ~Car() = default;

    Car(std::string car_reg_num, float price, std::reference_wrapper<Engine> car_engine);

    std::string carRegNum() const { return _car_reg_num; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::reference_wrapper<Engine> carEngine() const { return _car_engine; }
    void setCarEngine(const std::reference_wrapper<Engine> &car_engine) { _car_engine = car_engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
