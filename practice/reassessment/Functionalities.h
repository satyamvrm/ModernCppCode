#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include "Engine.h"
#include <iostream>
#include <functional>
#include <variant>
#include <vector>


using vtype = std::variant<Engine*,Car*>;
using Container = std::vector<vtype>;

void createObject(Container& data);
extern std::function<int(Container&)> avgHP;


#endif // FUNCTIONALITIES_H
