#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "VehicleType.h"
#include "TouristVehicle.h"
#include "Permit.h"
#include "PermitType.h"
#include "EmptyData.h"
#include<list>

using Vehicle = std::shared_ptr<TouristVehicle>;
using Container = std::list<Vehicle>;

void createObjects(Container& data);
void displayObjects(Container& data);

Container firstNInstanceOfTouristWithCondition(Container& data, int n);

float avgBookingCharges(Container& data, VehicleType t);

std::string maxBookingCharges(Container& data);

Container firstNInstance(Container& data, int n);




#endif // FUNCTIONALITIES_H
