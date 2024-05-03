/* 
    system which accept data values and "logic". This logic will be applied on every single data value recived and corresponding output will be shown
    fn(data,logic)
*/

#include<iostream>
#include<functional> //support for functional programming!

void Square(int num){
    std::cout<<"Square of : "<<num<<" -> "<<num*num<<'\n';
}
void Cube(int num){
    std::cout<<"Cube of : "<<num<<" -> "<<num*num*num<<'\n';
}

// int magic(){}// should be checked at call time 
//operation is higher function
//a higher order function either accept or returns(or both) another function 

//The Modern C++ version using function wrapper 
void Operation(const std::vector<int>& data, std::function<void(int)> fn){
    for(int val : data){
        fn(val);
    }
    std::cout<<"Lvalue function\n\n";
}

//we can make different function using function overloading and set it for rvalue using "&&"
void Operation(const std::vector<int>&& data, std::function<void(int)> fn){
    for(int val : data){
        fn(val);
    }
    std::cout<<"Rvalue function\n";
}



int main(){
    std::vector<int> arr = {1,2,3,4,5};
    Operation(arr,Square);
    Operation(std::vector<int>{5,4,3,2,1},Cube);
}

/*
    Higher order function
    Anonymous function
    functional programming paradigm
    no state
    immutable data
    currying
    First-class function
*/