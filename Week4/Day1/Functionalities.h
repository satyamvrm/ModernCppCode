#include <iostream>
#include "Employee.h"
#include <memory>
#include <algorithm>
#include <numeric>

using EmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee *>;
using EmpSmart = std::shared_ptr<Employee>;
using EmployeeSmartPointerContainer = std::vector<EmpSmart>;

void createEmployees(EmployeeContainer &data)
{
    data.push_back(
        Employee("Satyam", 89000.0f, "e101", "IT", 1));
    data.push_back(
        Employee("Devansh", 88000.0f, "e102", "Trainer", 1));
}

void createEmployeesPointer(EmployeePointerContainer &data)
{
    data.push_back(
        new Employee("Satyam", 89000.0f, "e101", "Trainer", 1));
    data.push_back(
        new Employee("Devansh", 88000.0f, "e102", "IT", 1));
}

void createEmployeesSmartPointer(EmployeeSmartPointerContainer &data)
{
    data.push_back(
        std::make_shared<Employee>("Satyam", 89000.0f, "e101", "IT", 1));
    data.push_back(
        std::make_shared<Employee>("Devansh", 88000.0f, "e102", "Trainer", 1));
}