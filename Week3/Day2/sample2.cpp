// Variadic Templates


#include<iostream>

/* add is a function whcih takes two interger parameters. It uses them as operands for binary addition the result of + operator applied on these operand */

template <typename T>
T add(T n){
    return n;
}

template<typename T, typename... R>
T add(T n1,R... args){
    return  n1 + add(args...);
}


int main(){
    std::cout << add<int>(10,12)<<'\n';
    std::cout << add<float>(10.2f,23.049f)<<'\n';
    std::cout << add<int>(10,10,433,4324,343,42)<<'\n';
    std::cout << add<int>('a','b')<<'\n';
    std::cout << add<int>(10,'a')<<'\n';
    std::cout << add<int>(10,'b','d')<<'\n';

}

/* 



*/