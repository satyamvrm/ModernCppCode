#ifndef FUNCATIONALITIES_H
#define FUNCATIONALITIES_H

#include<vector>
#include "Car.h"

// CreateObject is a top level function which takes one argument of type std::vector to car pointer BY REFERENCE.
void CreateObject(std::vector<Car*>& data);
void DisplayObjects(std::vector<Car *> &data);
void DeleteObject(std::vector<Car*>& data);
#endif // FUNCATIONALITIES_H
