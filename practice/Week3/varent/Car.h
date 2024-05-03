#ifndef CAR_H
#define CAR_H
#include<iostream>
class Car
{
private:
    std::string _name;
    std::string _regNo;
    int _noOfSeats;
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

    int getNoOfSeats() const { return _noOfSeats; }
    void setNoOfSeats(int noOfSeats_) { _noOfSeats = noOfSeats_; }

    std::string regNo() const { return _regNo; }
    void setRegNo(const std::string &regNo) { _regNo = regNo; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    Car(std::string name, std::string reg, int seats):_name{name},_regNo{reg},_noOfSeats{seats}{}

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "Car\n_name: " << rhs._name
           << " _regNo: " << rhs._regNo
           << " _noOfSeats: " << rhs._noOfSeats;
        return os;
    }
};

#endif // CAR_H
