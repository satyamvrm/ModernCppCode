#ifndef BRAND_H
#define BRAND_H

#include "Car.h"
#include "BrandType.h"
#include <array>
#include <memory>
#include <ostream>

class Brand
{
private:
    /* data */
    BrandType _brandType;
    std::string _tradeMark;
    std::array<std::reference_wrapper<Car>, 3> _cars;

public:
    Brand() = delete;
    Brand(const Brand &) = delete;
    Brand(Brand &&) = delete;
    Brand &operator=(const Brand &) = delete;
    Brand &operator=(Brand &&) = delete;
    ~Brand() = default;

    Brand(BrandType t, std::string name, std::array<std::reference_wrapper<Car>, 3> cars); 

    BrandType brandType() const { return _brandType; }
    void setBrandType(const BrandType &brandType) { _brandType = brandType; }

    std::string tradeMark() const { return _tradeMark; }
    void setTradeMark(const std::string &tradeMark) { _tradeMark = tradeMark; }

    std::array<std::reference_wrapper<Car>, 3> cars() const { return _cars; }
    void setCars(const std::array<std::reference_wrapper<Car>, 3> &cars) { _cars = cars; }

    friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);
};
std::string displayEnum(BrandType t);
void displayCars(std::array<std::reference_wrapper<Car>,3> arr);
#endif // BRAND_H
