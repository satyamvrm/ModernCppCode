#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include"CarType.h"
#include <ostream>

class Car : public Vehicle
{
private:
    CarType _car_type;

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

    Car(std::string regId, std::string name, float price, CarType type);

    CarType carType() const { return _car_type; }
    void setCarType(const CarType &car_type) { _car_type = car_type; }

    float CalculateServicingCost() override;

    float TaxExemptionAmount() override;

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);


};


#endif // CAR_H
