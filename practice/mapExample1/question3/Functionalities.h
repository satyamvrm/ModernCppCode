#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include "Bike.h"
#include "EmptyContainerException.h"
#include "InvalidRegistrationNumber.h"
#include <variant>
#include <list>
#include <memory>
#include <numeric>
#include <algorithm>

using Container = std::list<std::variant<std::shared_ptr<Car>, std::shared_ptr<Bike>>>;

void createObjests(Container &data);

void displayObjects(Container &data);

void firstAndLastObjectServicingCost(Container &data);

float totalTaxExemptionAmount(Container &data);

void displayPriceAndBrand(Container &data, std::string regNo);

#endif // FUNCTIONALITIES_H
