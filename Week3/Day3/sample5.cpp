#include <iostream>

/*
    Accept infinite parameters
    add 1 parameter with remaining

*/

/* Left associative and Right associative jarur dhyan rakhna hai MCQ imp  */

template <typename... T>
auto add(T... n)
{
    return (n + ...); // right associative (10 + (20 + (30 +40)))
    // return  (... + n); //left associative (((10 +20) + 30) + 40)
}

template <typename... T>
auto subtractR(T... n)
{
    return (n - ...);
}

template <typename... T>
auto subtractL(T... n)
{
    return (... - n);
}

int main()
{
    std::cout << add<int>(10, 12) << '\n';
    std::cout << add<float>(10.2f, 23.049f) << '\n';
    std::cout << add<int>(10, 10, 433, 4324, 343, 42) << '\n';
    std::cout << add<int>('a', 'b') << '\n';
    std::cout << subtractR(40, 30, 20) << '\n';
    std::cout << subtractL(40, 30, 20) << '\n';
}