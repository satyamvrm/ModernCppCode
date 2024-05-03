#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "VehicleCategory.h"
#include "TransmissionType.h"

class Vehicle
{
private:
    /* data */
    std::string _id;
    float _price;
    VehicleCategory _category;
    TransmissionType _type;
    unsigned int _bootSpace;
    bool _isInsured;

public:
    Vehicle(/* args */) = delete;
    Vehicle(const Vehicle &) = delete;
    Vehicle(Vehicle &&) = delete;
    Vehicle &operator=(const Vehicle &) = delete;
    Vehicle &operator=(Vehicle &&) = delete;
    ~Vehicle() = default;

    Vehicle(std::string id, float price, VehicleCategory category, TransmissionType type, unsigned int bootSpace, bool isInsured);

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    VehicleCategory category() const { return _category; }
    void setCategory(const VehicleCategory &category) { _category = category; }

    TransmissionType type() const { return _type; }
    void setType(const TransmissionType &type) { _type = type; }

    unsigned int bootSpace() const { return _bootSpace; }
    void setBootSpace(unsigned int bootSpace) { _bootSpace = bootSpace; }

    bool isInsured() const { return _isInsured; }
    void setIsInsured(bool isInsured) { _isInsured = isInsured; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};
std::string displayEnum(VehicleCategory t); 
std::string displayEnum(TransmissionType t); 
#endif // VEHICLE_H
