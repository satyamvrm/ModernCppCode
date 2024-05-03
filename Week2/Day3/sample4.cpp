#include<iostream>
#include<functional>
#include<array>
/* 
    Objective : 
        Design an adaptor function that accept a container of function wrappers and a container of data values.
        Map each function on each item in the data container and print the output

*/

using FnType = std::function<void(int)>;
using DataContainer = std::array<int, 5>;
using FnContainer = std::array<FnType, 3>;

void Adaptor(const FnContainer& fns, const DataContainer& data){
    for(const FnType fn : fns ){
        std::cout<<"Function : \n";
        for(int val : data){
            fn(val);
        }
        std::cout<<"\n";
    }
}   

int main(){
    FnContainer fns{
        [](int num){ std::cout<<num*num<<" ";},
        [](int num){ std::cout<<num*num*num<<" ";},
        [](int num){ std::cout<<num*num*num*num<<" ";},
    };
    Adaptor(fns, std::array<int,5>{1,2,3,4,5});
}