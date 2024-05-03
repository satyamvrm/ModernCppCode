#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(std::make_shared<EvCar>("C-101", "Honda", 50000.0f, EPowerType::ELECTIC, BatteryType::LI_ION));
    data.push_back(std::make_shared<EvCar>("C-102", "Honda", 120000.0f, EPowerType::HYBRID, BatteryType::NI_CAD));
    data.push_back(std::make_shared<EvCar>("C-103", "BMW", 130000.0f, EPowerType::HYBRID, BatteryType::OTHER));
    data.push_back(std::make_shared<ICECar>("C-104", "Mazda", 140000.0f, EngineType::DIESEL));
    data.push_back(std::make_shared<ICECar>("C-105", "Farrari", 150000.0f, EngineType::PETROL));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    for (auto c : data)
    {
        if (std::holds_alternative<EvCarPtr>(c))
        {
            EvCarPtr temp = std::get<EvCarPtr>(c);
            std::cout << *temp << '\n';
        }
        else
        {
            ICECarPtr temp = std::get<ICECarPtr>(c);
            std::cout << *temp << '\n';
        }
    }
}

Container CarLessThan600K(Container &data)
{
    /*
    if (data.empty())
        throw Exception("Data is Empty!");
    Container result(data.size());
    auto itr = std::copy_if(
        data.begin(),
        data.end(),

        result.begin(),
        [&](const CarVariant &c)
        {
            float price = std::visit([](auto &&val)
                                     { return val->price(); },
                                     c);
            return (price < 600000);
        });
    result.resize(std::distance(result.begin(),itr));
    return result;
    */

    if (data.empty())
        throw Exception("Data is Empty!");
    Container result;
    auto itr = std::copy_if(
        data.begin(),
        data.end(),

        std::inserter(result, result.begin()),
        [&](const CarVariant &c)
        {
            float price = std::visit([](auto &&val)
                                     { return val->price(); },
                                     c);
            return (price < 60000);
        });

    return result;
}

float averagePriceOfEvCar(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    int count{0};
    float sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float val, const CarVariant &c)
        {
            if (std::holds_alternative<EvCarPtr>(c))
            {
                count++;
                EvCarPtr temp = std::get<EvCarPtr>(c);
                return val + temp->price();
            }
            else
                return val;
        });
    return sum / count;
}

int countOfEvCar(Container &data, EPowerType t)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    return std::count_if(
        data.begin(),
        data.end(),
        [&](const CarVariant &c)
        {
            if (std::holds_alternative<EvCarPtr>(c))
            {
                EvCarPtr temp = std::get<EvCarPtr>(c);
                if (temp->engineType() == t)
                    return true;
                return false;
            }
            return false;
        });
}

std::string findBrandNameById(Container &data, std::string id)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::string name;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const CarVariant &c)
        {
            return std::visit([&](auto &&val)
                              { if(id == val->id()) name = val->brandName(); },
                              c);
        });
    return name;
}

std::unordered_set<BatteryType> findUniqueBatteryType(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::unordered_set<BatteryType> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const CarVariant &c)
        {
            if (std::holds_alternative<EvCarPtr>(c))
            {
                auto temp = std::get<EvCarPtr>(c);
                result.insert(temp->batteryType());
            }
        });
    return result;
}

bool atLeastOneAbove60K(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    return std::any_of(
        data.begin(),
        data.end(),
        [&](const CarVariant& c){
            return std::visit([](auto&& val){return val->price()>60000;},c);
        }
    );
}
