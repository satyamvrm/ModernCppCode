#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"
#include "EmptyContainerException.h"
#include<unordered_map>
#include<future>
using Container = std::unordered_map<int,std::shared_ptr<Employee>>;

/* To create objects of employees */
void createObjects(Container& data);

/* To display all the object in list */
void displayObjects(Container& data);

/* to count instance of object in list */
int countBudgetOver5000(Container& data);

/* To check all employee get salary above 10000 */
bool allSalaryAbove10K(Container& data);

/* To calculate the average tax exemption */
float AverageTaxExemption(Container& data);

/* To display first n instance */
void firstNInstances(Container& data, int n);

#endif // FUNCTIONALITIES_H
