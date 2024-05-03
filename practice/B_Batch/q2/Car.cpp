#include "Car.h"
std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "_car_reg_num: " << rhs._car_reg_num
       << " _price: " << rhs._price
       << " _car_engine: " << rhs._car_engine.get();
    return os;
}

Car::Car(std::string car_reg_num, float price, std::reference_wrapper<Engine> car_engine)
    : _car_reg_num{car_reg_num}, _price{price}, _car_engine{car_engine}
{
}