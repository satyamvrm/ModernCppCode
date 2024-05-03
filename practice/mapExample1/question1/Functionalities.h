#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Automobile.h"
#include "EmptyContainerException.h"
#include <map>
#include <memory>

using Container = std::map<int,std::shared_ptr<Automobile>>;

/* To Create Objects in the Container which is list */
void createObjects(Container& data);

/* To display all objects */
void displayObjects(Container& data);

/* To calculate the average milage of all automobiles and retuning the float value and taking list of objects */
float averageMilage(Container& data);

/* To Count the instance of the particular type taking input as a second parameter in list of objects and returning the count */
int countInstanceAutomobileType(Container& data, AutomobileType t);

/* to check weather atleast one instance have price over 20000 or not in list of object */
bool anyInstanceAbove20000(Container& data);

#endif // FUNCTIONALITIES_H
