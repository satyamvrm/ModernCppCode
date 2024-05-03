#include <iostream>
#include <cstring>

int main()
{

    char c[1];
    std::cin >> c;
    try
    {
        if (*c == '1' || *c == '2')
            std::cout << c;
        else
            throw std::runtime_error("Invalid Input");
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Invalid Input 2\n";
    }
    return 0;
}