#ifndef BRAND_H
#define BRAND_H

#include <iostream>
#include <memory>
#include <vector>
#include "Car.h"

using carPtr = std::shared_ptr<Car>;
using CarArray = std::vector<std::reference_wrapper<carPtr>>;

class Brand
{
private:
    /* data */
    std::string _name;
    CarArray _cars;

public:
    Brand(/* args */) = delete;
    Brand(const Brand &) = delete;
    Brand(const Brand &&) = delete;
    Brand &operator=(Brand &) = delete;
    Brand &operator=(Brand &&) = delete;
    ~Brand() = default;

    Brand(std::string name, CarArray cars);

    std::string name() const
    {
        return _name;
    }
    void setName(const std::string &name) { _name = name; }

    std::vector<std::reference_wrapper<std::shared_ptr<Car>>> cars() const { return _cars; }
    void setCars(const std::vector<std::reference_wrapper<std::shared_ptr<Car>>> &cars) { _cars = cars; }

    friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);
};

#endif // BRAND_H
