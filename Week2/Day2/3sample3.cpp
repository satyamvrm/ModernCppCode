/* 
    Objective : Design an adaptor to accept
        a vector of integers
        a predicate (a function that returns true or false based on a single input)

        Use the predicate to print data from the vector

    Example : 
        std::vector<int> {10,12,13,15,14}
        odd num : 13 15
        divisible by 2 : 10 12 14
        divisible by 3 : 12 15
        divisible by 5 : 10 15
        .
        .
        .
*/

#include<iostream>
#include<vector>
#include<functional>

void Adaptor(std::function<bool(int)> predicate,const std::vector<int>& data){
    for(int val : data){
        if(predicate(val)){std::cout<<val<<" ";}
    }
}

int main(){
    std::cout<<"\nnum%5=0\n";
    Adaptor(
        [](int number){ return number%5==0;},
        std::vector<int>{10,12,14,15,13}
    );

    std::cout<<"\nnum%5=0 && num%3==0\n";
    Adaptor(
        [](int number){ return number%3&&number%5==0;},
        std::vector<int>{10,12,14,15,13}
    );

    std::cout<<"\nnum%3==0\n";
    Adaptor(
        [](int number){ return number%3==0;},
        std::vector<int>{10,12,14,15,13}
    );

    std::cout<<"\nnum%2==0\n";
    Adaptor(
        [](int number){ return number%2==0;},
        std::vector<int>{10,12,14,15,13}
    );

    std::cout<<"\nnum%7==0\n";
    Adaptor(
        [](int number){ return number%7==0;},
        std::vector<int>{10,12,14,15,13}
    );
    std::cout<<'\n';
}
