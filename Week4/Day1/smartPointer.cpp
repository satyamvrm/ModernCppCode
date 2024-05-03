/*
    Smart pointer : They are wrappers around raw pointers to allow better memory management using RAII design pattern
    There are three type of smart pointer :
        - shared_ptr
        - unique_ptr
        - weak_ptr : stalker pointer [shared pointer --> token]
*/

/*
        <------------------20 bytes-------------->
        [                      |                  ]
         <------12 bytes------> <-----8 bytes----->
        ptr1                    ptr2

*/

#include <iostream>
#include <memory>
#include "Employee.h"
#include <thread>
#include <mutex>

std::mutex mt;
bool allThreadRun = 0;

void changeName(std::shared_ptr<Employee> owner2)
{
    std::lock_guard<std::mutex> lg(mt);
    owner2->setName("Satyam Verma");
    std::cout << "\nOwner 2 :- \n"
              << *owner2 << '\n';
}

void updateSalary(std::shared_ptr<Employee> owner3)
{
    std::lock_guard<std::mutex> lg(mt);
    owner3->setSalary(2500000);
    std::cout << "\nOwner 3 :- \n"
              << *owner3 << '\n';
}

int main()
{
    std::shared_ptr<Employee> ptr = std::make_shared<Employee>("Satyam", 8000, "e101", "Trainee", 1);
    std::cout << "Before :- \n"
              << *ptr << '\n';

    std::thread t1(&changeName, ptr);
    std::thread t2(&updateSalary, ptr);

    if (std::lock_guard<std::mutex> lg(mt); !allThreadRun)
        std::cout << "\n\nVeryImportant :- " << *ptr << '\n';

    t1.join();
    t2.join();
}