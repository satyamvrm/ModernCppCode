/*
    Hashtable
        Key is integer(employee ID)
        value is Employee object on stack
*/

#include<iostream>
#include<unordered_map>
#include "Employee.h"
#include<memory>

template<typename K, typename V>
void Display(const std::unordered_map<K,V>& mapData){
    for(auto& [key,value] : mapData){
        std::cout<<key<<'\t'<<*value<<'\n';
    }
}

template <typename K,typename V>
void createObject(std::unordered_map<K,V>& mapData){
    mapData.emplace(101,new Employee("Satyam",80000.0f,"101","IT",1));
    mapData.emplace(102,new Employee("Ayush",80000.0f,"102","IT",1));
}

template<typename K, typename V>
void DisplaySmart(const std::unordered_map<K,V>& mapData){
    for(auto& [key,value] : mapData){
        std::cout<<key<<'\t'<<value<<'\n';
    }
}

template <typename K,typename V>
void createObjectSmart(std::unordered_map<K,V>& mapData){
    mapData.emplace(101,std::make_shared<Employee>("Satyam",80000.0f,"101","IT",1));
    mapData.emplace(102,std::make_shared<Employee>("Ayush",80000.0f,"102","IT",1));
}

int main(){
    std::unordered_map<int,std::shared_ptr<Employee>> mapData;
    createObject<int,std::shared_ptr<Employee>>(mapData);
    Display<int,std::shared_ptr<Employee>>(mapData);
}