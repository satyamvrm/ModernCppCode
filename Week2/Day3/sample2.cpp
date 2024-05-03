#include <iostream>
#include <functional>

class Action
{
private:
    int _id{10};

public:
    Action() = default;
    ~Action() = default;
    void Operation(int num)
    {
        std::cout << _id * num << '\n';
    }
};

int main()
{
    Action obj;
    /* A non static member of a class mandatorily call by referance  */
    auto binded_Operation = std::bind(&Action::Operation, &obj, 10);
    binded_Operation(); //a1.operation(10);
    obj.Operation(40);
}