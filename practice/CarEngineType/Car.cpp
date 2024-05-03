#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    string type{""};
    if(rhs.m_type==CarType::SEDAN) type="Sedan";
    else if(rhs.m_type==CarType::HATCHBACK) type="Hatchback";
    else if(rhs.m_type==CarType::SUV) type="SUV";
    os << "\nm_name: " << rhs.m_name
       << "\nm_price: " << rhs.m_price
       << "\nm_model: " << rhs.m_model
       << "\nm_engine: " << *rhs.m_engine
       << " m_type: " << type;
    return os;
}

Car::Car(string name, float price, string model, std::shared_ptr<Engine> engine, CarType type)
    : m_name{name}, m_price{price}, m_model{model}, m_engine{engine}, m_type{type}{}

