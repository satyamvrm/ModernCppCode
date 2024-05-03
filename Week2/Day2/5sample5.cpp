/*
triggers app
f1----------> f2(2 integers will be created)
                predicate to filter the data
*/

// void f2(int n1, int n2){
//     auto lambda_fn = [](int n1, int n2) { return n1+n2 ;};
//     lambda_fn(10,20);
// }

#include <functional>
#include <iostream>

std::function<int()> f2(int n1, int n2)
{
    auto lambda_fn = [&]()
    {  int val =99; return n1+n2+10+20+val; };
    lambda_fn();
    return lambda_fn;
}

void f1()
{
    int n1 = 10;
    int n2 = 20;
    f2(n1, n2);

    std::function<int()> modified_function = f2(n1, n2);
    std::cout << modified_function() << "\n";
}

int main()
{
    f1();
}

/*
     Main in stack memory


     f1 stack memory
     n1           n2
     [10]        [20]
     0x76        0x0H

     f2 stack memory
     n1          n2
     [10]       [20]
     0x76       0x0H

     f2  stack memory
     n1         n2
     [10]       []


    void magic(){
        int n1=10, n2=20;
        example 1: all data values from "enclosed function are accessible inside f1"
        auto f1 = [&]() {return n1+n2;}
        //only n1 is accessible , n2 is not we get error

        example 2: selected data values capture by copy
        auto f1 = [n1,n2](){return n1+n2;}
        //both are accessible as copied

        example 3 : selected data values capture by referance
        auto f1 = [&n1,&n2](){return n1+n2;}
        //both are accessible as referance

        example 4 : all data values capture by copy
        auto f1 = [=](){return n1+n2+n3;}
        //n1, n2 and n3 are accessible as copy

        example 5 : some values by copy, some by referance
        auto f1 = [n1, &n2, &n3](){return n1+n2+n3}
        //n1 will be copied and rest by referance

    }
*/

void trick(){
    int n1 = 100;
    auto f1 = [=]() mutable {n1=99;};
    std::cout<<n1<<'\n'; //100
}