#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
class Vehicle
{
private:
    std::string _registration_number;
    std::string _brand;
    float _price;
public:
    //default constructor disabled
    Vehicle()=delete;
    //default copy constructor disabled
    Vehicle(const Vehicle&) = delete;
    // default move constructor disabled 
    Vehicle(const Vehicle&&) = delete;
    // default assignment operator disabled 
    Vehicle &operator=(const Vehicle&) = delete; 
    // default move operator disabled
    Vehicle &operator=(const Vehicle&&) = delete; 
    // default distructor enabled 
    virtual ~Vehicle()=default;

    // parameterize constructor
    Vehicle(std::string regNo, std::string name, float price);

    virtual float CalculateServicingCost() = 0;

    virtual float TaxExemptionAmount();

    std::string registrationNumber() const { return _registration_number; }
    void setRegistrationNumber(const std::string &registration_number) { _registration_number = registration_number; }

    std::string brand() const { return _brand; }
    void setBrand(const std::string &brand) { _brand = brand; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
