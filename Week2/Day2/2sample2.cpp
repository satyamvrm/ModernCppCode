
/* 
    Objective : Create an adaptor which takes:
        1. A callable of the following signature
            Input : int ans int
            Output : void
        2. integer number n1
        3. integer number n2

        The adaptor must apply/amp the callable on the n1 & n2
*/

#include<iostream>
#include<functional>

/*
    Adaptor is a higher order function that accepts 
    a. A function wrapper for all functions that have the following signature.
         i. int, int input parameter
        ii. void as return type 
*/

void Adaptor(std::function<void(int,int)> fn, int n1, int n2){
    fn(n1,n2);
}

void f1(int n1,int n2){
    std::cout<<n1+n2<<std::endl;
}
int main(){
    Adaptor(
        [](int n1,int n2){std::cout<<n2-n1<<'\n';},
        11,22
    );
    Adaptor(
        [](int n1,int n2){std::cout<<n2*n1<<'\n';},
        11,22
    );
    Adaptor(
        f1,
        11,22
    );
}