#ifndef BUS_H
#define BUS_H

#include<iostream>

class Bus
{
private:
    std::string _name;
    std::string _regNo;
    std::string _busType;
public:
    //default constructor disabled
    Bus()=delete;
    //default copy constructor disabled
    Bus(const Bus&) = delete;
    // default move constructor disabled 
    Bus(const Bus&&) = delete;
    // default assignment operator disabled 
    Bus &operator=(const Bus&) = delete; 
    // default move operator disabled
    Bus &operator=(const Bus&&) = delete; 
    // default distructor enabled 
    ~Bus()=default;

    std::string busType() const { return _busType; }
    void setBusType(const std::string &busType) { _busType = busType; }

    std::string regNo() const { return _regNo; }
    void setRegNo(const std::string &regNo) { _regNo = regNo; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    Bus(std::string name,std::string reg,std::string type):_name{name},_regNo{reg},_busType{type}{}

    friend std::ostream &operator<<(std::ostream &os, const Bus &rhs) {
        os << "Bus\n_name: " << rhs._name
           << " _regNo: " << rhs._regNo
           << " _busType: " << rhs._busType;
        return os;
    }
};

#endif // BUS_H
