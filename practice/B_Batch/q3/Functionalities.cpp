#include "Functionalities.h"

void createObjects(Container &data)
{
    data.emplace("C-101", std::make_shared<CarUnit>("Honda", 100000.0f, CarType::SEDAN, 240, 6000, CarGear::CLASSIC));
    data.emplace("C-102", std::make_shared<CarUnit>("BMW", 110000.0f, CarType::HATCHBACK, 310, 7000, CarGear::PRNDL));
    data.emplace("C-103", std::make_shared<CarUnit>("Honda", 120000.0f, CarType::HATCHBACK, 240, 6000, CarGear::TIPTRONIC));
    data.emplace("C-104", std::make_shared<CarUnit>("BMW", 130000.0f, CarType::SEDAN, 320, 7000, CarGear::CLASSIC));
    data.emplace("C-105", std::make_shared<CarUnit>("Honda", 140000.0f, CarType::SUV, 280, 6000, CarGear::TIPTRONIC));
    data.emplace("C-106", std::make_shared<CarUnit>("BMW", 150000.0f, CarType::SEDAN, 330, 7000, CarGear::PRNDL));
}

void display(Container &data)
{
    if (data.empty())
        throw EmptyDataContainerException("Data is Empty\n");
    for (const std::pair<std::string, CarPtr> &c : data)
    {
        std::cout << c.first << '\t' << *c.second << '\n';
    }
}

bool allSameGear(Container &data)
{
    bool c = std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPtr> &c)
        {
            return c.second->gear() == CarGear::CLASSIC;
        });
    bool p = std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPtr> &c)
        {
            return c.second->gear() == CarGear::PRNDL;
        });
    bool t = std::all_of(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, CarPtr> &c)
        {
            return c.second->gear() == CarGear::TIPTRONIC;
        });
    return c || t || p;
}

std::optional<std::vector<CarPtr>> findInstances(Container &data, CarType t)
{
    if (data.empty())
        throw EmptyDataContainerException("Data is empty");
    std::vector<CarPtr> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string,CarPtr>& c){
            if(c.second->type()==t)  result.push_back(c.second);
        }
    );
    if(result.empty()) return std::nullopt;
    return result;
}

float lowestSpeedPrice(Container &data)
{
    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string,CarPtr>& c1,const std::pair<std::string,CarPtr>& c2){
            return c1.second->topSpeed()<c2.second->topSpeed();
        }
    );
    return itr->second->price();
}

int topRPMbyID(Container &data, std::string id)
{
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string,CarPtr>& c){
            return c.first == id;
        }
    );
    return itr->second->topRpm();
}

int countabove(Container &data, float p)
{
    return std::count_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string,CarPtr>& c){
            return c.second->price()>p;
        }
    );
}
