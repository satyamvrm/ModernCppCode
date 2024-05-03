#ifndef CAR_H
#define CAR_H

#include "CarType.h"
#include "Engine.h"
#include<iostream>
#include<memory>

using string = std::string;

class Car
{
private:
    string m_name;
    float m_price;
    string m_model;
    std::shared_ptr<Engine> m_engine;
    CarType m_type;

public:
    
    //default constructor deleted
    Car()=delete;
    //default copy constructor deleted
    Car(const Car&) = delete;
    // default move constructor deleted 
    Car(const Car&&) = delete;
    // default assignment operator deleted 
    Car &operator=(const Car&) = delete; 
    // default move operator deleted
    Car &operator=(const Car&&) = delete; 
    // default distructor enabled 
    ~Car()=default;

    //parameterized constructor
    Car(string name, float price, string model, std::shared_ptr<Engine> engine, CarType type);

    string name() const { return m_name; }
    void setName(const string &name) { m_name = name; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    string model() const { return m_model; }
    void setModel(const string &model) { m_model = model; }

    CarType type() const { return m_type; }
    void setType(const CarType &type) { m_type = type; }

    std::shared_ptr<Engine> engine() const { return m_engine; }
    void setEngine(const std::shared_ptr<Engine> &engine) { m_engine = engine; }

    //ofstream operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
