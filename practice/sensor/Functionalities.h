#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<memory>

#include "Sensor.h"
#include "EmptyData.h"
#include<list>

using Container = std::list<std::shared_ptr<Sensor>>;

void CreateObjects(Container& data);
void showReadings(Container& data);
int showCount(Container& data);
int NumberOfType(Container& data, SensorTypes type);

#endif // FUNCTIONALITIES_H
