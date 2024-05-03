#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "CarUnit.h"
#include"EmptyDataContainerException.h"
#include<memory>
#include<unordered_set>
#include<functional>
#include<algorithm>


using CarPtr = std::shared_ptr<CarUnit>;
using Container = std::unordered_map<std::string,CarPtr>;

void createObjects(Container& data);
void display(Container& data);

bool allSameGear(Container& data);

std::optional<std::vector<CarPtr>> findInstances(Container& data,CarType t);

float lowestSpeedPrice(Container& data);

int topRPMbyID(Container& data, std::string id);

int countabove(Container& data,float p);



#endif // FUNCTIONALITIES_H
