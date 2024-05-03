#include "Functionalities.h"

void createObject(Container &data)
{
    data.push_back(new Engine(1, 2));
    data.push_back(new Engine(12, 23));
    data.push_back(new Engine(12, 12));
}

std::function<void(Container &)> avgHP = [](Container &data)
{
    int sum{0}, count{0};
    for (auto e : data)
    {
        if (std::holds_alternative<Engine *>(e))
        {
            Engine *temp = std::get<Engine *>(e);
            sum += temp->getHp();
            count++;
        }
    }
    std::cout << "HP :- " << sum / count<<'\n';
};