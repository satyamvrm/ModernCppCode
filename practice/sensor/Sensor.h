#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include "SensorType.h"
class Sensor
{
private:
    int _id;
    std::string _name;
    SensorTypes _type;
    int _reading;

public:
    //default constructor disabled
    Sensor()=delete;
    //default copy constructor disabled
    Sensor(const Sensor&) = delete;
    // default move constructor disabled 
    Sensor(const Sensor&&) = delete;
    // default assignment operator disabled 
    Sensor &operator=(const Sensor&) = delete; 
    // default move operator disabled
    Sensor &operator=(const Sensor&&) = delete; 
    // default distructor enabled 
    ~Sensor()=default;

    //parameterized constructor
    Sensor(int id,std::string name, SensorTypes type, int reading);

    int id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    SensorTypes type() const { return _type; }

    int reading() const { return _reading; }

    friend std::ostream &operator<<(std::ostream &os, const Sensor &rhs);

};
std::string displayType(SensorTypes type);
#endif // SENSOR_H
