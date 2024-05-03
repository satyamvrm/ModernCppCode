#include <algorithm>
#include "Functionalities.h"
#include "Employee.h"

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    std::cout << std::boolalpha << std::any_of(
        data1.begin(), 
        data1.end(), 
        [](const Employee &emp)
        { return emp.salary() > 1000; }
    );
    std::cout<<'\n';
    std::cout<< std::boolalpha << std::any_of(
        data2.begin(),
        data2.end(),
        [](const Employee* emp){return emp->salary()>50000;}
    );
    std::cout<<'\n';
    std::cout<< std::boolalpha << std::any_of(
        data3.begin(),
        data3.end(),
        [](const EmpSmart& emp){return emp->salary()>50000;}
    );
    std::cout<<'\n';
}