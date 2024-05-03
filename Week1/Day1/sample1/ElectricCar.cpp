#include "ElectricCar.h"

float ElectricCar::Drive()
{
    return _range;
}

ElectricCar::ElectricCar(std::string name, int acceleration, int topSpeed, float price, int batteryCap, float time, float motor, float range, float maxp)
    : Car(name,acceleration,topSpeed,price), _batterCapacity{batteryCap}, _timeToCharge{time}, _motorPower{motor}, _range{range}, _maxPower(maxp){}

void ElectricCar::ShowElectricCarDetails()
{
    std::cout << " _batterCapacity: " << _batterCapacity << std::endl 
              << " _timeToCharge: " << _timeToCharge << std::endl
              << " _motorPower: " << _motorPower << std::endl
              << " _range: " << _range << std::endl
              << " _maxPower: " << _maxPower << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs)
{
    os << static_cast<const Car &>(rhs)
       << " _batterCapacity: " << rhs._batterCapacity
       << " _timeToCharge: " << rhs._timeToCharge
       << " _motorPower: " << rhs._motorPower
       << " _range: " << rhs._range
       << " _maxPower: " << rhs._maxPower;
    return os;
}
