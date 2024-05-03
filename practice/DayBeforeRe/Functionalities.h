#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include <algorithm>
#include <numeric>
#include <list>
#include <queue>
#include <vector>
#include <memory>
#include <functional>
#include <mutex>
#include "Exception.h"
#include <unordered_map>
#include <unordered_set>
#include <optional>

using VehiclePtr = std::shared_ptr<Vehicle>;
using Container = std::list<VehiclePtr>;
using PQContainer = std::priority_queue<VehiclePtr, std::vector<VehiclePtr>, std::function<bool(const VehiclePtr &v1, const VehiclePtr &v2)>>;

// function to create objects and display objects
void createObject(Container &data);
void displayObjects(Container &data);

// function to return list of transmission type of last n instance
TransmissionType *lastNtransmissionType(Container &data, int n);

// function to return a priority queue
PQContainer dataInPQ(Container &data, std::function<bool(const VehiclePtr &v1, const VehiclePtr &v2)> fn);
void Display(PQContainer data);

// function to return unordered set of vehicle ptr
std::unordered_set<float> uniquePrice(Container &data);

// function to return unordered map
std::unordered_map<std::string, Category> nIdCategoryPair(Container &data, int n);

// function to return array of bootspace value
int *bootSpaceValues(Container &data);

// funtcion to apply a uniuary function
std::vector<float> unararyFunction(Container &data, std::optional<std::function<float(const VehiclePtr &v)>> fn = std::nullopt);

// funtion to return all insured vehicle
std::optional<Container> isInsured(Container& data);

#endif // FUNCTIONALITIES_H
