#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<optional>
#include<list>
#include "Vehicle.h"
#include<functional>
#include<memory>
#include<future>
#include "Car.h"

using carPtr = std::shared_ptr<Car>;
using Container = std::list<carPtr>;
using stringContainer = std::list<std::string>;

extern std::function<std::optional<Container>(Container&,float)> carAboveThreshold;
extern std::function<std::optional<std::list<float>>(Container&,VehicleType)> returnCarPrice;
extern std::function<std::optional<stringContainer>(Container&)> returnCarsColourContainer;
extern std::function<float(Container&)> avgInsurance;

#endif // FUNCTIONALITIES_H
