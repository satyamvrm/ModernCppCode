#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "ConfirmedTrip.h"
#include<list>
#include "EmptyData.h"
#include<memory>

using Container = std::list<std::shared_ptr<ConfirmedTrip>>;

void createObjects(Container& data);
void displayObjects(Container& data);
float findAverageTravelTime(Container& data);
float findMinimumTimeTravel(Container& data);
int findCount(Container& data, CarType type);

#endif // FUNCTIONALITIES_H
