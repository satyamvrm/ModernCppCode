#include "Functionalities.h"

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    //////////////////////////////////////////////////////////////////////////////////
    /* 
        Count If : count instances matching with given condition, condition is written as predicate. return value final count 
    */
    std ::cout << std::count_if(
        data1.begin(),
        data1.end(),
        [](const Employee &emp)
        {
            return emp.salary() > 50000;
        });

    std ::cout << '\n' << std::count_if(
        data2.begin(),
        data2.end(),
        [](const Employee *emp)
        {
            return emp->id() == "e101";
        });

    std ::cout << '\n' << std::count_if(
        data3.begin(),
        data3.end(),
        [](const std::shared_ptr<Employee> &emp)
        {
            return emp->yearOfExperience() == 1;
        });
    std::cout<<'\n';
}