#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "VehicleType.h"
#include "TouristVehicle.h"
#include "Permit.h"
#include "PermitType.h"
#include "EmptyData.h"
#include<list>

using Vehicle = std::shared_ptr<TouristVehicle>;
using PermitPtr = std::shared_ptr<Permit>;
using ContainerV = std::vector<Vehicle>;
using ContainerP = std::vector<PermitPtr>;


void createObjects(ContainerV& data1, ContainerP& data2);
void displayObjects(ContainerV& data1, ContainerP& data2);
void deleteVehicle(ContainerV& data, int n);
void deletePermit(ContainerP& data);

ContainerV firstNInstanceOfTouristWithCondition(ContainerV& data, int n);

float avgBookingCharges(ContainerV& data, VehicleType t);

std::string maxBookingCharges(ContainerV& data);

ContainerV firstNInstance(ContainerV& data, int n);




#endif // FUNCTIONALITIES_H
