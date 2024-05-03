#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Brand.h"
#include <vector>
#include <algorithm>

using BrandPtr = std::shared_ptr<Brand>;
using BrandContainer = std::vector<BrandPtr>;
using CarContainer = std::vector<Car *>;

// 1
void createObjects(BrandContainer &brands, CarContainer &cars);
void DisplayObjects(BrandContainer &data);

// 2
std::vector<std::string> BrandByBrandType(BrandContainer &data, BrandType t);

// 3
std::vector<Car *> CarsAboveThreshold(BrandContainer &data, float p);

// 4
ChassisType ChassisTypeOfCheapestCar(BrandContainer &data);

// 5
bool allHave4seats(BrandContainer &data);

#endif // FUNCTIONALITIES_H
