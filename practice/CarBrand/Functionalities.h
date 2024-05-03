#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Brand.h"
#include <algorithm>
#include <numeric>

using BrandPtr = std::shared_ptr<Brand>;
using Container = std::vector<BrandPtr>;
using CarContainer = std::vector<carPtr>;

void createObjects(Container &brands, CarContainer &Cars);
void display(Container &data);
#endif // FUNCTIONALITIES_H
