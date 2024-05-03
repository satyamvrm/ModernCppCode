#include <algorithm>
#include "Functionalities.h"
#include "Employee.h"
#include <numeric>
#include<list>

/*
    Functional Programming
        - map : apply a logic(function) on all items in data collection (one by one)
        - filter : extracting itmes that staisfy a condtion from the data collection
        - reduce : collection/summarizing/gathering/converting multiple items into a single item based on a binary operation

        e.g. 10,20,30,40,50
            - reduce 5 number into 1 number by summation aggregration
            - reduce 5 number into 1 number by product aggregration

    ["Satyam" | 80000 | "Trainee" | 10]
    ["Ayush" | 88000 | "IT" | 10]
    ["Himanshu" | 80000 | "HR" | 10]
    ["Ksritij" | 80000 | "CEO" | 10]


    AUCV - answer upto current value

    init/AUCV
    0.0f        80000           88000       80000           80000
    |           |               |           |               |
    |           |               |           |               |
    -------------               |           |               |
        |                       |           |               |
        |                       |           |               |
        80000 [AUCV]            |           |               |
        |                       |           |               |
        |                       |           |               |
        -------------------------           |               |
                    |                       |               |
                    |                       |               |
                    168000                  80000           |
                    |                       |               |
                    -------------------------               |
                                |                           |
                                248000                      |
                                |                           |
                                -----------------------------
                                                |
                                                |
                                                328000



*/

int main()
{
    std::list<int> data{100,4,9,16,25};
    std::cout<<"Data without lambda"<<std::accumulate(data.begin(),data.end(),0);
    std::cout<<'\n';

    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    createEmployees(data1);
    createEmployeesPointer(data2);
    createEmployeesSmartPointer(data3);

    /*
        rule 1 : default operation is binary+ / operator+();
    */
    std::cout << "Accumalate Sum of salary of employees using simple class :- ";
    std::cout << std::accumulate(
        data1.begin(),
        data1.end(),
        0.0f,
        [](float answer_upto_current_point, const Employee emp)
        {
            return answer_upto_current_point + emp.salary();
        });


    std::cout << "\nSum of all Employees using Employee pointer :- ";
    std::cout << std::accumulate(
        data2.begin(),
        data2.end(),
        0.0f,
        [](float answer_upto_current_point, const Employee *emp)
        {
            return answer_upto_current_point - emp->salary();
        });

        
    std::cout << "\nSmart pointer sum :- ";
    std::cout << std::accumulate(
        data3.begin(),
        data3.end(),
        1.0f,
        [](float answer_upto_current_point, const EmpSmart emp)
        {
            return answer_upto_current_point * emp->salary();
        });
    std::cout << '\n';
    
}