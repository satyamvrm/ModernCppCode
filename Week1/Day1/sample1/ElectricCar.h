#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H
#include "Car.h"
#include <ostream>
class ElectricCar : public Car
{
private:
    /* data */
    int _batterCapacity {0};
    float _timeToCharge {0.0f};
    float _motorPower {0.0f};
    float _range {0};
    float _maxPower {0.0f};

public:
    ElectricCar(/* args */) = default;              // default constructor enable
    ElectricCar(const ElectricCar&) = delete;               // disable copy costructor
    ElectricCar(ElectricCar&&) = delete;                    // disable move constructor //brand new in c++
    ElectricCar& operator=(const ElectricCar&) = delete;    // disable assignment operator //brand new in c++
    ElectricCar& operator=(ElectricCar&&) = delete;         // disable move assignment operator
    ~ElectricCar() = default;                       // distructor
    
    float Drive() override;
    ElectricCar(std::string name, int acceleration, int topSpeed, float price ,int batteryCap, float time, float motor, float range, float maxp);
    
    void ShowElectricCarDetails();

    int batterCapacity() const { return _batterCapacity; }
    void setBatterCapacity(int batterCapacity) { _batterCapacity = batterCapacity; }

    float timeToCharge() const { return _timeToCharge; }
    void setTimeToCharge(float timeToCharge) { _timeToCharge = timeToCharge; }

    float motorPower() const { return _motorPower; }
    void setMotorPower(float motorPower) { _motorPower = motorPower; }

    float maxPower() const { return _maxPower; }
    void setMaxPower(float maxPower) { _maxPower = maxPower; }

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);

    
};

#endif // ELECTRICCAR_H
