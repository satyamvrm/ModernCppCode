// composition of engine

#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include<iostream>
#include "CarType.h"
class Car
{
private:
    /* data */
    std::string _id;
    float _price;
    std::string _model;
    Engine* _engine;
    CarType _type;

public:
    Car(/* args */) = delete;
    Car(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator=(const Car&) = delete;
    Car&& operator=(Car&&) = delete;

    Car(std::string id, float price, std::string model, Engine* engine, CarType ctype);
    Car(std::string id, std::string model, Engine* engine, CarType ctype);
    
    ~Car() = default;

    std::string id() const { return _id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string model() const { return _model; }

    Engine* engine() const { return _engine; }
    void setEngine(Engine* engine) { _engine = engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
