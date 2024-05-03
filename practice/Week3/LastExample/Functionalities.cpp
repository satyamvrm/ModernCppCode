#include "Functionalities.h"

std::function<std::optional<Container>(Container &, float)> carAboveThreshold =
    [](Container &data, float amount) -> std::optional<Container>
{
    Container result;
    if (data.empty())
        throw std::runtime_error("Data is Empty\n");
    if (amount <= 0)
        throw std::runtime_error("Inalid Thrashold\n");
    for (carPtr c : data)
    {
        if (c->carPrice() > amount)
            result.push_back(c);
    }
    if (result.empty())
        return std::nullopt;
    return result;
};

std::function<std::optional<std::list<float>>(Container &, VehicleType)> returnCarPrice =
    [](Container &data, VehicleType t) -> std::optional<std::list<float>>
{
    if (data.empty())
        throw std::runtime_error("Data is Empty\n");
    std::list<float> result;
    for (auto c : data)
    {
        if (c->type() == t)
            result.push_back(c->carPrice());
    }
    if (result.empty())
        return std::nullopt;
    return result;
};

std::function<std::optional<stringContainer>(Container &)> returnCarsColourContainer =
    [](Container &data) -> std::optional<stringContainer>
{
    if (data.empty())
        throw std::runtime_error("Data is Empty\n");
    stringContainer result;
    for (auto c : data)
    {
        if (c->type() == VehicleType::Private)
            result.push_back(c->getCarColour());
    }
    if (result.empty())
        return std::nullopt;
    return result;
};

std::function<float(Container &)> avgInsurance = [](Container &data) -> float
{
    if (data.empty())
        throw std::runtime_error("Data is Empty\n");
    float sum{0.0f};
    for (auto c : data)
    {
        sum = sum + c->carPrice();
    }
    return sum/data.size();
};