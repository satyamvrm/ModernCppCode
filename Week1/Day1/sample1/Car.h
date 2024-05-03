#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car
{
private:
    /* data */
    std::string _name {""};
    int _acceleration {0};
    int _topSpeed {0};
    float _xShowRoomPrice {0.0f};

public:
    Car(/* args */) = default;              // default constructor enable
    Car(const Car&) = delete;               // disable copy costructor
    Car(Car&&) = delete;                    // disable move constructor //brand new in c++
    Car& operator=(const Car&) = delete;    // disable assignment operator //brand new in c++
    Car& operator=(Car&&) = delete;         // disable move assignment operator
    virtual ~Car() = default;                       // distructor

    Car(std::string name, int acceleration, int topSpeed, float price);

    //getter and setter
    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _topSpeed; }
    void setTopSpeed(int topSpeed) { _topSpeed = topSpeed; }

    float xShowRoomPrice() const { return _xShowRoomPrice; }
    void setXShowRoomPrice(float xShowRoomPrice) { _xShowRoomPrice = xShowRoomPrice; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    virtual float Drive() = 0;

};

#endif // CAR_H
