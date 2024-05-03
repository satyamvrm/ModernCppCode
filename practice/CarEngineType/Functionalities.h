#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Car.h"
#include "Engine.h"
#include "CarType.h"
#include <vector>
using Container = std::vector<std::shared_ptr<Car>>;

void CreateObject(Container& data);
// void DeleteObjects(Container& data);
void DisplayObjects(Container& data);

int TotalHorsePower(Container& data);

#endif // FUNCTIONALITIES_H
