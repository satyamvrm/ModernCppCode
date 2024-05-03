#include <algorithm>
#include "Functionalities.h"
#include "Employee.h"

/*
for copy if:
  1. this is a copy operation. copy semantic has to be supported
  2. we don't know how many instnces will satisfy the condition
  3. to copy from source to be destination, destination has already be initiated with the memory allocatement
*/

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    EmployeeContainer result1(data1.size());
    // Employee Class
    std::copy(
        data1.begin(),
        data1.end(),
        result1.begin()
    );
    // copy all element from beginning of upto but not includeing the end of data1 to the result1 vector from the begonning of result1

    EmployeePointerContainer result2(data2.size());
    // Employee Class
    std::copy(
        data2.begin(),
        data2.end(),
        result2.begin()
    );

    for(auto c : result1){
        std::cout<<c<<'\n';
    }
    

    // CopyIf 
    EmployeeContainer result3(data1.size());
    auto itr = std::copy_if(
        data1.begin(),
        data1.end(),
        result3.begin(),
        [](const Employee& emp){return emp.salary()>88000.0f;}
    );
    std::size_t actual_size = std::distance(result3.begin(),itr);
    result3.resize(actual_size);
    std::cout<<"\n\nCopy If : -\n";
    for(auto c : result3){
        std::cout<<c<<'\n';
    }


}