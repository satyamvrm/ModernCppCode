#ifndef DIESELCAR_H
#define DIESELCAR_H

#include "Car.h"
#include <ostream>
class DieselCar  :public Car
{
private:
    int _fuelCapacity;
    float _milage;
public:
    // default constructor
    DieselCar() = default;
    // default copy constructor disabled
    DieselCar(const DieselCar &) = delete;
    // default move constructor disabled
    DieselCar(const DieselCar &&) = delete;
    // default assignment operator disabled
    DieselCar &operator=(const DieselCar &) = delete;
    // default move operator disabled
    DieselCar &operator=(const DieselCar &&) = delete;
    // default distructor enabled
    ~DieselCar() = default;


    DieselCar(std::string name, int acceleration, int topSpeed, float price, int fuel, float milage)
    : Car(name,acceleration,topSpeed,price), _fuelCapacity{fuel}, _milage{milage} {}


    DieselCar(int fule, float milage);
    float Drive() override;

    int fuelCapacity() const { return _fuelCapacity; }
    void setFuelCapacity(int fuelCapacity) { _fuelCapacity = fuelCapacity; }

    float milage() const { return _milage; }
    void setMilage(float milage) { _milage = milage; }

    friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);

   

};

#endif // DIESELCAR_H
