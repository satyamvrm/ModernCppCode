#include "Functionalities.h"

void createObject(Container1 &data, EngineVector &e)
{
    e.push_back(std::make_shared<Engine>("E-Bike", 100, EngineType::EV));
    e.push_back(std::make_shared<Engine>("E-Car", 200, EngineType::ICE));

    data.push(std::make_shared<Bike>("B-101", "Honda", BikeType::CLASSIC, 10, *e[0]));
    data.push(std::make_shared<Car>("C-101", "Honda", CarType::HATCHBACK, 30, *e[1]));
    data.push(std::make_shared<Bike>("B-102", "Honda", BikeType::CLASSIC, 20, *e[0]));
    data.push(std::make_shared<Car>("C-102", "Honda", CarType::SUV, 40, *e[1]));
}

void displayObject(Container1 data)
{
    while (!data.empty())
    {
        /* code */
        std::visit([&](auto &&o)
                   { std::cout << *o << '\n'; },
                   data.top());
        data.pop();
    }
}

std::map<std::string, CarPtr> allCarsWithIds(Container1 data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::broken_promise);
    std::map<std::string, CarPtr> result;
    while (!data.empty())
    {
        if (std::holds_alternative<CarPtr>(data.top()))
        {
            CarPtr temp = std::get<CarPtr>(data.top());
            result.emplace(temp->carId(), temp);
        }
        data.pop();
    }
    return result;
}

std::map<std::string, BikePtr> allBikesWithIds(Container1 data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    std::map<std::string, BikePtr> result;
    while (!data.empty())
    {
        if (std::holds_alternative<BikePtr>(data.top()))
        {
            BikePtr temp = std::get<BikePtr>(data.top());
            result.emplace(temp->bikeId(), temp);
        }
        data.pop();
    }
    return result;
}

Container2 mapToPQ(std::map<std::string, BikePtr> data)
{
    Container2 result;

    for(auto a : data){
        result.push(a.second);
    }

    return result;
}

void createObject(Container2 &data, EngineVector &e)
{
    e.push_back(std::make_shared<Engine>("E-Bike", 100, EngineType::EV));
    e.push_back(std::make_shared<Engine>("E-Car", 200, EngineType::ICE));

    data.push(std::make_shared<Bike>("B-101", "Honda", BikeType::CLASSIC, 10, *e[0]));
    data.push(std::make_shared<Car>("C-101", "Honda", CarType::HATCHBACK, 30, *e[1]));
    data.push(std::make_shared<Bike>("B-102", "Honda", BikeType::CLASSIC, 20, *e[0]));
    data.push(std::make_shared<Car>("C-102", "Honda", CarType::SUV, 40, *e[1]));
}

void displayObject(Container2 data)
{
    while (!data.empty())
    {
        /* code */
        std::visit([&](auto &&o)
                   { std::cout << *o << '\n'; },
                   data.top());
        data.pop();
    }
}
