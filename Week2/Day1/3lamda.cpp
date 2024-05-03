/*
    system which accept data values and "logic". This logic will be applied on every single data value recived and corresponding output will be shown
    fn(data,logic)
*/

#include <iostream>
#include <functional> //support for functional programming!

void Square(int num)
{
    std::cout << "Square of : " << num << " -> " << num * num << '\n';
}
void Cube(int num)
{
    std::cout << "Cube of : " << num << " -> " << num * num * num << '\n';
}

// int magic(){}// should be checked at call time
// operation is higher function
// a higher order function either accept or returns(or both) another function

// The Modern C++ version using function wrapper
void Operation(const std::vector<int> &data, std::function<void(int)> fn)
{
    for (int val : data)
    {
        fn(val);
    }
    std::cout << "Lvalue function\n\n";
}

// we can make different function using function overloading and set it for rvalue using "&&"
void Operation(const std::vector<int> &&data, std::function<void(int)> fn)
{
    for (int val : data)
    {
        fn(val);
    }
    std::cout << "Rvalue function\n";
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    auto f1 = [](int number) -> void
    {
        std::cout << "Square of : " << number << " -> " << number * number << '\n';
    };
    f1(10);
    Operation(
        arr,
        f1);
    Operation(
        arr,
        [](int number)
        {
            std::cout << "Square of : " << number << " -> " << number * number * number << '\n';
        });
}
// by not setting the function to a lvalue we have saved the effeciency and the function will get distroyed after the operation function completion

//cpp con aurthor back-to-basic 2015 lambda function/ function wrapper

// [] are capture clause used for lambda creation