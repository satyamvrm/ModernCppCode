#include <iostream>
#include <functional>
#include <vector>

using Container = std::vector<std::function<void(int)>>;

void Adaptor(Container &fn, std::vector<int> &data)
{
    for (auto f : fn)
    {

        for (auto d : data)
        {
            f(d);
        }
    }
}

int main()
{
    std::vector<int> data{10, 20, 30, 40};
    Container fn{
        [](int num){ std::cout << num * num << '\n'; },
        [](int num){ std::cout << 10 + num * num << '\n'; },
        [](int num){ std::cout << 50 * num << '\n'; },
    };
    Adaptor(fn,data);
}