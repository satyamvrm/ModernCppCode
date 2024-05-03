#include<iostream>
#include<functional>
#include<array>
// std::ref shortcut for stander references

void funct(int &i){
    ++i;
}

int main(){
    int local = 0;
    auto bound = std::bind(funct, std::ref(local));
    bound();
    std::cout<<local<<'\n';
    bound();
    std::cout<<local<<'\n';
    
    const std::array<int,3> data {1,2,3};
    auto accumulator = [sum=0](int value) mutable{
        sum+=value;
        return sum;
    };
    std::for_each(data.begin(),data.end(),std::ref(accumulator));
    std::cout<< accumulator(0);
}