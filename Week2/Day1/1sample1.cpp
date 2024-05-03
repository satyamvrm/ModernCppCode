/* 
    system which accept data values and "logic". This logic will be applied on every single data value recived and corresponding output will be shown fn(data,logic)
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
// operation is higher function
// a higher order function either accept or returns(or both) another function 
/*

// the c way to call the function pointer
void Operation(int* arr, int size, void(*ptr)(int)){
    for(int i=0;i<size;i++){
        (*ptr)(arr[i]);
    }
} 
*/

//The Modern C++ version using function wrapper 
void Operation(int* arr, int size, std::function<void(int)> fn){
    for(int i=0;i<size;i++){
        fn(arr[i]);
    }
}



int main(){
    void (*ptr)(int) = Square;
    void (*ptr2)(int) = Cube;
    int arr[5] = {10,20,30,40,50};
    // Operation(arr,5,magic); //types matter when we call the pointer should properly the the right functionat the call
    Operation(arr,5,Square);
    Operation(arr,2,Cube);
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