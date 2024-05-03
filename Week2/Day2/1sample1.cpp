#include<iostream>
#include<functional>

/* The actual datatype of lambda is unkown */

void Magic(std::function<void(int)> fn){
    fn(10);
}

/* 
class Function_wrapper{
    //........
    private:
    f <------- lambda is saved to this member
    oe = operator() {f()}
} */

int main(){
    auto f1 = [](int number) {std::cout<<number*10;};
    f1(10); //like a function, operator () operator
    Magic([](int number){std::cout<<number*10;});
}