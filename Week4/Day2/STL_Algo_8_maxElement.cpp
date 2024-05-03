
#include <algorithm>
#include "Functionalities.h"
#include "Employee.h"
#include <numeric>

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    // desiganation of employee whoes salary is highest
    auto temp = std::max_element(
        data1.begin(),
        data1.end(),
        [](const Employee &e1, const Employee &e2)
        { return e1.salary() < e2.salary(); }); // comparison logic or comparator

    std::cout<<*temp<<'\n';

    auto temp2 = std::min_element(
        data2.begin(),
        data2.end(),
        [](const Employee *e1, const Employee *e2)
        { return e1->salary() < e2->salary(); }); // comparison logic or comparator

    std::cout<<**temp2 <<'\n';

    auto temp3 = std::max_element(
        data3.begin(),
        data3.end(),
        [](const EmpSmart &e1, const EmpSmart &e2)
        { return e1->salary() == e2->salary(); }); // comparison logic or comparator

    std::cout<<**temp3<<'\n';

}