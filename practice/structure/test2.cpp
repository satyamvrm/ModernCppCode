#include<iostream>

enum class num {
    ONE,
    TWO
};

int main(){
    int a;
    std::cin>>a;
    num user = static_cast<num>(a);
    if(user==num::ONE)
    std::cout<<"ONE";
    else std::cout<<"Two";
}