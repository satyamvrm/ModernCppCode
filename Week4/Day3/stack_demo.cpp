/*
    A situation where only one elemnet needs to be accessed and it is the most recent item inserted into the container

    e.g. : A complier execute function calls

    f1(){
        f2()
    }

    call stack

    f2 <----- recently added, top most entry. will be accessed first

    f1 <----- still pending

    stack is not itratable means we can't print all data of stack by looping over it

*/

#include<stack>
#include "Employee.h"
#include "Functionalities.h"

using Container = std::stack<Employee>; 

int main(){
    Container s1;
    s1.push(Employee("A", 89000.0f, "e101", "IT", 1));
    s1.push(Employee("B", 89000.0f, "e102", "IT", 1));

    std::cout<<s1.top()<<'\n';
}