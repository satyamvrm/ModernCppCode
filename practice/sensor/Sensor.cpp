#include "Sensor.h"
std::ostream &operator<<(std::ostream &os, const Sensor &rhs) {
    os << "_id: " << rhs._id<<'\n'
       << " _name: " << rhs._name<<'\n'
       << " _type: " << displayType(rhs.type())<<'\n'
       << " _reading: " << rhs._reading<<'\n';
    return os;
}

Sensor::Sensor(int id, std::string name, SensorTypes type, int reading) :
    _id{id}, _name{name}, _type{type}, _reading{reading}
{}

std::string displayType(SensorTypes type)
{
    std::string str{};
    if(type==SensorTypes::CABIN_PRESSURE) str="CABIN_PRESSURE"; 
    else if(type==SensorTypes::TEMPERATURE) str="TEMPERATURE"; 
    else if(type==SensorTypes::TYPE_PRESSURE) str="TYPE_PRESSURE"; 
    return str;
}