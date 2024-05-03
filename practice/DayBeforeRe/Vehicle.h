#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Category.h"
#include "TransmissonType.h"

class Vehicle
{
private:
    /* data */
    std::string _id;
    float _price;
    Category _vCategory;
    TransmissionType _type;
    unsigned int _bootSpace;
    bool _insured;

public:
    Vehicle() = delete;
    Vehicle(Vehicle &) = delete;
    Vehicle(Vehicle &&) = delete;
    Vehicle &operator=(Vehicle &) = delete;
    Vehicle &operator=(Vehicle &&) = delete;
    ~Vehicle() = default;

    Vehicle(
        std::string id,
        float price,
        Category vCategory,
        TransmissionType type,
        unsigned int bootSpace,
        bool insured);

    bool insured() const { return _insured; }

    unsigned int bootSpace() const { return _bootSpace; }

    TransmissionType type() const { return _type; }

    Category vCategory() const { return _vCategory; }

    float price() const { return _price; }

    std::string id() const { return _id; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

std::string displayEnum(Category t);
std::string displayEnum(TransmissionType t);

#endif // VEHICLE_H
