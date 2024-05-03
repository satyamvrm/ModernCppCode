#ifndef BIKE_H
#define BIKE_H
#include<iostream>
class Bike
{
private:
    std::string _name;
    std::string _regNo;
    std::string _breakType;
public:
    //default constructor disabled
    Bike()=default;
    //default copy constructor disabled
    Bike(const Bike&) = delete;
    // default move constructor disabled 
    Bike(const Bike&&) = delete;
    // default assignment operator disabled 
    Bike &operator=(const Bike&) = delete; 
    // default move operator disabled
    Bike &operator=(const Bike&&) = delete; 
    // default distructor enabled 
    ~Bike()=default;

    Bike(std::string name,std::string reg, std::string type): _name{name}, _regNo{reg}, _breakType{type}{}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    std::string regNo() const { return _regNo; }
    void setRegNo(const std::string &regNo) { _regNo = regNo; }

    std::string breakType() const { return _breakType; }
    void setBreakType(const std::string &breakType) { _breakType = breakType; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
        os << "Bike\n_name: " << rhs._name
           << " _regNo: " << rhs._regNo
           << " _breakType: " << rhs._breakType;
        return os;
    }
    
};

#endif // BIKE_H
