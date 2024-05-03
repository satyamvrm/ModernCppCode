#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "CarType.h"
#include <ostream>
#include<iostream>

class Car : public Vehicle
{
private:
    CarType _carType;
    float _carPrice;
    std::string _carColour;
    
public:
    //default constructor disabled
    Car()=delete;
    //default copy constructor disabled
    Car(const Car&) = delete;
    // default move constructor disabled 
    Car(const Car&&) = delete;
    // default assignment operator disabled 
    Car &operator=(const Car&) = delete; 
    // default move operator disabled
    Car &operator=(const Car&&) = delete; 
    // default distructor enabled 
    ~Car()=default;

    CarType carType() const { return _carType; }
    void setCarType(const CarType &carType) { _carType = carType; }

    float carPrice() const { return _carPrice; }
    void setCarPrice(float carPrice) { _carPrice = carPrice; }

    std::string getCarColour() const { return _carColour; }
    void setCarColour(const std::string &carColour_) { _carColour = carColour_; }

    Car(std::variant<int,std::string> type, int reg, VehicleType vtype, std::reference_wrapper<std::shared_ptr<Insurance>> insurance, CarType ctype, float price, std::string colour);

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    
};
std::string displayCar(CarType t);

#endif // CAR_H
