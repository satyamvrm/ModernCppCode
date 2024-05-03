#include <cstring>
#include <iostream>
#include <functional>
#include <list>
/*
    1. we connot massively change code after it is deployed for clinet
    2. sometime api parameters need to be fixed at a certain value
*/

void Formula(const int x, const int y, const int z)
{
    std::cout << "Answer : " << ((x + y) - z) << '\n';
}

void Magic(const std::list<int> &data, int n)
{
    for (int val : data)
    {
        n--;
        if (n == 0)
        {
            std::cout <<"The value in the given list :- " << val << '\n';
        }
    }
}



int main()
{
    Formula(10, 30, 20);
    auto binded_formula = std::bind(&Formula, 100, std::placeholders::_1, std::placeholders::_2);
    binded_formula(30, 120);

    auto binded_Magic = std::bind(&Magic, std::placeholders::_2, std::placeholders::_1);

    auto binded_strcpy = std::bind(&strcpy, std::placeholders::_2, std::placeholders::_1);

    char* msg = new char[30];
    binded_strcpy("Satyam",msg);
    std::cout<<"msg : "<<msg<<'\n';
    std::list<int> lst = {1,2,3,4,5};
    binded_Magic(2,lst);

    auto fn = [](int number, int factor){std::cout<<"The multiple :- "<<number*factor<<'\n';};

    // a lambda is a object. using & on a lambda means taking address of object. Don't use & sign with lambda in bind

    auto binded_lambda_fn = std::bind(fn,std::placeholders::_1,40);

    binded_lambda_fn(100);

    delete[] msg;
}

/* A function variable stores the address of first instruction as the array stores the address of first element */
