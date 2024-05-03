#ifndef FUNCTIONILITIES_H
#define FUNCTIONILITIES_H

#include<array>
#include "Car.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"
#include<unordered_map>
#include<memory>

using CarPointer = std::shared_ptr<Car>;
using Container = std::unordered_map<std::string,CarPointer>;
// using Container = std::array<Car*,3>; 

/* older way 
void CreateObjects(std::array<Car*, 3>& data);
void DeleteObjects(std::array<Car*, 3>& data); */

void CreateObjects(Container& data);

// input : container -> output :int 
int totalHorsePower(const Container& data);


/* 
    Is this condition true or false : all cars in the container have a price above 700K
 */
bool isAllCarAbove700K(const Container& data);

/* 
    return th engine pointer of the car whose price is lowest if multiple car instances have the same minimum, consider first minimum found
 */
Engine* enginePointerToMinPrice(const Container& data);

/* find the average torque for the engine in the car */
float avgEngineTorque(const Container& data);

// Function to print the model name of the car whose is is passed as a parameter
std::string findCarModelByID(const Container& data, const std::string carID);


#endif // FUNCTIONILITIES_H
