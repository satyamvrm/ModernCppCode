#include "Functionalities.h"
#include <functional>

template <typename T, typename P>
auto Search(T Employees, const P &fn)
{
    auto itr = std::find_if(
        Employees.begin(),
        Employees.end(),
        fn);
    if (itr == Employees.end())
    {
        std::cerr << "Object not found \n";
        return itr;
    }
    else
    {

        std::cout << "Object found\n";
        return itr;
    }
}

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    /*
        Find-If :
            - std::find_if return iterator to the first object
            - if match is not found, find_if returns end iterator
    */
    auto itr1 = Search<EmployeeContainer&, std::function<bool(Employee &)>>(data1, [](const Employee &emp)
                                                                           { return emp.id() == "e101"; });
    std::cout << *itr1 << '\n';
    auto itr2 = Search<EmployeePointerContainer&, std::function<bool(Employee *)>>(data2, [](const Employee *emp)
                                                                                  { return emp->id() == "e102"; });
    std::cout << **itr2 << '\n';
    auto itr3 = Search<EmployeeSmartPointerContainer&, std::function<bool(EmpSmart &)>>(data3, [](EmpSmart &emp)
                                                                                       { return emp->id() == "e103"; });
    std::cout << *itr3 << '\n';
}