/*
    Hashtable
        Key is integer(employee ID)
        value is Employee object on stack
*/

#include<iostream>
#include<unordered_map>
#include "Employee.h"

template<typename K, typename V>
void Display(const std::unordered_map<K,V>& mapData){
    for(auto& [key,value] : mapData){
        std::cout<<key<<'\t'<<value<<'\n';
    }
}

template <typename K,typename V>
void createObject(std::unordered_map<K,V>& mapData){
    mapData.emplace(101,Employee("Satyam",80000.0f,"101","IT",1));
    mapData.emplace(102,Employee("Ayush",80000.0f,"102","IT",1));
}

int main(){
    std::unordered_map<int,Employee> mapData;
    createObject<int,Employee>(mapData);
    Display<int,Employee>(mapData);
}