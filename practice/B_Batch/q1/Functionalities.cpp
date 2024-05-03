#include "Functionalities.h"

void createObject(Container &data)
{
    data.push_back(std::make_shared<EvCar>("C-101", 4, Platform::IC_BASED, 2.8f, 4, 120));
    data.push_back(std::make_shared<EvCar>("C-102", 3, Platform::PURE_EV, 4.18f, 5, 80));
    data.push_back(std::make_shared<EvCar>("C-103", 6, Platform::IC_BASED, 2.8f, 7, 150));
    data.push_back(std::make_shared<EvCar>("C-104", 5, Platform::PURE_EV, 3.4f, 3, 130));
    data.push_back(std::make_shared<EvCar>("C-105", 4, Platform::IC_BASED, 3.8f, 2, 200));
}

void display(Container &data)
{
    std::for_each(
        data.begin(),
        data.end(),
        [](CarPtr &c)
        {
            std::cout << *c << '\n';
        });
}

std::optional<std::list<CarPtr>> firstNinstance(Container &data, int n)
{
    if (data.empty())
        throw EmptyDataContainerException("Data is Empty\n");

    std::list<CarPtr> result;
    std::for_each_n(
        data.begin(),
        n,
        [&](CarPtr &c)
        {
            result.emplace_back(c);
        });
    if (result.empty())
        return std::nullopt;
    return result;
}

int countAboveThreshhold(Container &data)
{
    return std::count_if(
        data.begin(),
        data.end(),
        [](const CarPtr &c)
        { return c->chassisLength() > 2.7; });
}

int speedOfCar(Container &data, std::string id)
{
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](CarPtr &c)
        { return c->carId() == id; });
    return itr->get()->topSpeed();
}

std::optional<Container> satisfiedCars(Container &data, std::function<bool(CarPtr)> fn)
{
    Container result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](CarPtr &c)
        {
            if (fn(c))
            {
                result.push_back(c);
                return 1;
            }
            else
                return 0;
        });

    if (result.empty())
        return std::nullopt;
    return result;
}

bool atleastOne(Container &data)
{
    return std::any_of(data.begin(), data.end(), [](const CarPtr &c)
                       { return c->platform() == Platform::PURE_EV; });
}
