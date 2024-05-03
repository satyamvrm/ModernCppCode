#include <iostream>
#include <variant>

int main()
{
    std::variant<int, std::string> name;
    std::string tempnam;
    std::cin >> tempnam;
    name=tempnam;
    if (std::holds_alternative<std::string>(name))
    {
        std::cout << std::get<std::string>(name) << '\n';
    }
    if (std::holds_alternative<int>(name))
    {
        std::cout << std::get<int>(name) << '\n';
    }
}