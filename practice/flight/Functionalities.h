#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Flight.h"
#include<list>
#include<functional>
#include<memory>

using FlightPtr = std::shared_ptr<Flight>;
using Container = std::list<FlightPtr>;
using FunctionContainer = std::list<std::function<int(Container&)>>;


void createObjects(Container& data);

void displayObjects(Container& data);

void operations(Container& data, FunctionContainer& functions);

extern std::function<int(Container&)> over50SeatsFlights;

extern std::function<std::string(Container&)> longestFlightDistace;

extern std::function<float(Container&)> highestFlightSeats;

extern std::function<int(Container&)> highestEntries;



#endif // FUNCTIONALITIES_H
