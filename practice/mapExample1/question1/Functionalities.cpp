#include "Functionalities.h"
#include <algorithm>
#include <numeric>

// object creation
void createObjects(Container &data)
{
    data.emplace(
        1,
        std::make_shared<Automobile>(
            "Honda City",
            AutomobileType::PRIVATE,
            12000.0f,
            15.0f));
    data.emplace(
        2,
        std::make_shared<Automobile>(
            "BMW X7",
            AutomobileType::PRIVATE,
            22000.0f,
            10.0f));
    data.emplace(
        3,

        std::make_shared<Automobile>(
            "Honda WR-V",
            AutomobileType::TRANSPORT,
            15000.0f,
            13.0f));
    data.emplace(
        4,
        std::make_shared<Automobile>(
            "BMW Z5",
            AutomobileType::PRIVATE,
            24000.0f,
            8.0f));
}

// displaying all the objects
void displayObjects(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("No Objects in the given list");
    for (auto [k, v] : data)
    {
        std::cout << k << " - " << *v << '\n';
    }
}

// calculating the average milage
float averageMilage(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("No Objects in the given list");
    float sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float val,const std::pair<int, std::shared_ptr<Automobile>> &c2)
        {
            return val + c2.second->automobileMileage();
        });
    return sum / data.size();
}

// counting the instance of given type
int countInstanceAutomobileType(Container &data, AutomobileType t)
{
    if (data.empty())
        throw EmptyContainerException("No Objects in the given list");
    int count = std::count_if(
        data.begin(),
        data.end(),
        [&](const std::pair<int, std::shared_ptr<Automobile>>&row)
        {
            return row.second->automobileType() == t;
        });
    return count;
}

// checking of any object is above 20000 price
bool anyInstanceAbove20000(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("No Objects in the given list");
    bool result = std::any_of(
        data.begin(),
        data.end(),
        [](const std::pair<int, std::shared_ptr<Automobile>> &row)
        {
            return row.second->automobilePrice() > 20000;
        });
    return result;
}
