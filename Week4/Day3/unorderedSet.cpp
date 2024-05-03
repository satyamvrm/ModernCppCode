/*
    11,  12,  11,  13,  11,  12

    hash function : mod 4
    11%4 = 3
    12%4 = 0
    11%4 = 3 //key already exist

    Set Hash Table
    key     Value
    12      12
    11      11
    
*/

#include<iostream>
#include "Employee.h"
#include<unordered_set>

int main(){
    std::unordered_set<int> s1{11,12,11,13,11,14};
    auto pair = s1.insert(11);
    if(pair.second){
        std::cout<<"Element Added\n";
    }else{
        std::cout<<"Element Not Added\n";
    }

    std::unordered_set<Employee> emp{
        Employee("Satyam", 89000.0f, "e101", "IT", 1),
        Employee("Verma", 89000.0f, "e102", "IT", 1)
    };
    std::cout<<(*emp.begin())<<'\n';
}
