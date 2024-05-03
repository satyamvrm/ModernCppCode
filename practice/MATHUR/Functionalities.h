#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include "Car.h"
#include <variant>
#include <functional>
#include <vector>
#include <iostream>

using vtype = std::variant<Engine *, Car *>;
using Container = std::vector<vtype>;

void createObject(Container &data);
extern std::function<void(Container &)> avgHP;

#endif // FUNCTIONALITIES_H
