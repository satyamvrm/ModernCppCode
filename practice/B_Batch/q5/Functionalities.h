#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include "Exception.h"
#include <list>
#include <vector>
#include <queue>
#include <memory>
#include <functional>
#include <algorithm>
#include <optional>
#include <unordered_set>
#include <unordered_map>

using VehiclePtr = std::shared_ptr<Vehicle>;
using VehicleContainer = std::list<VehiclePtr>;
using fn = std::function<bool(const VehiclePtr &c1, const VehiclePtr &c2)>;
using PriorityQueue = std::priority_queue<VehiclePtr, std::vector<VehiclePtr>, fn>;

// 1
void createObject(VehicleContainer &data);
void displayObject(VehicleContainer &data);

// 2
std::optional<std::vector<TransmissionType>> lastNinstance(VehicleContainer &data, int n);

std::optional<TransmissionType*> lastNinstanceC(VehicleContainer &data, int n);

// 3
PriorityQueue sortedByFunction(const VehicleContainer &data, const fn &f);

// 4
std::unordered_set<float> uniquePrice(VehicleContainer &data);

// 5
std::unordered_map<std::string,VehicleCategory> IdCategoryMap(VehicleContainer& data, int n);

//6
int* bootSpaceList(VehicleContainer& data);

//7
VehicleContainer insuredVehicels(VehicleContainer& data);

//8
std::vector<unsigned int> unaryBootSpace(VehicleContainer& data,std::function<int(VehiclePtr&)> fn);

#endif // FUNCTIONALITIES_H
