#include <iostream>
#include <future>

int Factorial(std::future<int> &ft)
{
    // line can be executed before int
    int *ptr = (int *)malloc(sizeof(int)); 

    //the program 
    int n = ft.get();

    // wait for event
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    *ptr = result;
    // std::cout << "Final answer :- " << *ptr << '\n';
    return *ptr;
}

int main()
{
    //  make a promise to compiler
    //  -I will give you an integer IN FUTURE
    std::promise<int> pr; // made a promise uesd for setting th value
    std::future<int> ft = pr.get_future();

    /* Promise is used to set the vaule in producer thread and future is use to get the value in consumer set */
    std::future<int> result = std::async(&Factorial, std::ref(ft));
    int value=0;
    std::cin>>value;
    pr.set_value(value);

    //what if main wants to do something after Factorial?
    result.wait();
    std::cout<<"Result :- "<<result.get()<<'\n';
    std::cout<<"Good Bye\n";


}