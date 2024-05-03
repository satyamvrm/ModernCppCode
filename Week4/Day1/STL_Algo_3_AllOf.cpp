#include "Functionalities.h"
#include <functional>


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

   std::cout<<std::boolalpha<<std::all_of(
        data1.begin(),
        data1.end(),
        [](const Employee& emp){return emp.salary()>500.0f;}
   );

}