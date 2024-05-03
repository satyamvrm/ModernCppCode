#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include <vector>

using CompanyContainer = std::vector<Emplpoyeee *>;
using EmployeeContainer = std::vector<Company *>;

void createObjects(EmployeeContainer &cData, CompanyContainer &eData)
{
    eData.push_back(
        new Company(101, "ABC"));
    eData.push_back(
        new Company(102, "BCD"));
    eData.push_back(
        new Company(103, "CDE"));
    eData.push_back(
        new Company(104, "DEF"));
    cData.push_back(
        new Emplpoyeee("ABC", *eData[0]));
    cData.push_back(
        new Emplpoyeee("BCD", *eData[1]));
    cData.push_back(
        new Emplpoyeee("CDE", *eData[2]));
    cData.push_back(
        new Emplpoyeee("DEF", *eData[3]));
}

void displayCompanies(CompanyContainer &data)
{
    if (data.empty())
        std::cout << "Data is empty";
    for (Emplpoyeee *c : data)
    {
        if (c)
            std::cout << *c << '\n';
        continue;
    }
}

void displayEmployies(EmployeeContainer &data)
{
    if (data.empty())
        std::cout << "Data is empty";
    for (Company *c : data)
    {
        std::cout << *c << '\n';
    }
}

void deleteEmplyeeFromCompany(CompanyContainer &data)
{
    if (data.empty())
        std::cout << "Data is empty";
    delete data.back();
    data.pop_back();
}

void DeleteEmployeFromEmploye(EmployeeContainer &data)
{
    if (data.empty())
        std::cout << "Data is empty";
    delete data.back();
    data.pop_back();
    
}

#endif // FUNCTIONALITIES_H
