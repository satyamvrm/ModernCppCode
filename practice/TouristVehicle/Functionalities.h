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

float AverageDuration(Container& data);
Container nInstance(Container& data, int n);
PermitType minimumRenualCharge(Container& data);

#endif // FUNCTIONALITIES_H
