#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "EvCar.h"
#include "ICECar.h"
#include "Exception.h"
#include <memory>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <variant>
#include <unordered_set>

// alias
using EvCarPtr = std::shared_ptr<EvCar>;
using ICECarPtr = std::shared_ptr<ICECar>;
using CarVariant = std::variant<EvCarPtr, ICECarPtr>;
using Container = std::vector<CarVariant>;

void createObjects(Container &data);
void displayObjects(Container &data);

Container CarLessThan600K(Container &data);

float averagePriceOfEvCar(Container &data);

int countOfEvCar(Container &data, EPowerType t);

std::string findBrandNameById(Container &data, std::string id);

std::unordered_set<BatteryType> findUniqueBatteryType(Container &data);

bool atLeastOneAbove60K(Container &data);


#endif // FUNCTIONALITIES_H
