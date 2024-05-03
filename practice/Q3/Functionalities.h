#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <variant>
#include <memory>
#include <vector>
#include <mutex> 
#include <thread>
#include <algorithm>
#include <numeric>
#include "EvCar.h"
#include "ICECar.h"
#include "ClassType.h"
#include "EmptyContainerException.h"
#include "SizeExceedException.h"
#include "TypeNotFound.h"
#include "BatteryCapacityExceeds.h"

using EvCarPointer = std::shared_ptr<EvCar>;
using EVCarContainer = std::vector<EvCarPointer>;
using ICECarPointer = std::shared_ptr<ICECar>;
using VType = std::variant<EvCarPointer, ICECarPointer>;
using Container = std::vector<VType>;

void CreateObject(Container& data);
void NInstances(Container& data, ClassType type, int n);
bool TankCapacity(Container& data);
void CountICECar(Container& data);
Container BatteryThreshold(Container& data, float threshold);
void Display(Container& data);
void DisplayNth(Container& data, int n);



#endif // FUNCTIONALITIES_H