#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "EvCar.h"
#include "EmptyDataContainerException.h"
#include <memory>
#include <algorithm>
#include <list>
#include <vector>
#include <functional>

using CarPtr = std::shared_ptr<EvCar>;
using Container = std::vector<CarPtr>;

void createObject(Container &data);
void display(Container &data);
std::optional<std::list<CarPtr>> firstNinstance(Container &data, int n);
int countAboveThreshhold(Container &data);
int speedOfCar(Container &data, std::string id);
std::optional<Container> satisfiedCars(Container &data, std::function<bool(CarPtr)> fn);
bool atleastOne(Container &data);

#endif // FUNCTIONALITIES_H
