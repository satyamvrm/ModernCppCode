#include "Functionalities.h"
#include <cstring>
void createObjests(Container &data)
{
    data.emplace_back(
        std::make_shared<Bike>(
            "RJ04SL6726",
            "HERO",
            85000.0f,
            BrakingSystem::ABS));
    data.emplace_back(
        std::make_shared<Bike>(
            "RJ04SL6727",
            "HERO",
            85000.0f,
            BrakingSystem::TRADITIONAL));
    data.emplace_back(
        std::make_shared<Car>(
            "UP53H0777",
            "Toyota",
            850000.0f,
            CarType::COMMUTE));
    data.emplace_back(
        std::make_shared<Car>(
            "PB65HT0777",
            "Mahindra",
            250000.0f,
            CarType::COMMERCIAL));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    for (auto v : data)
    {
        if (std::holds_alternative<std::shared_ptr<Bike>>(v))
        {
            auto temp = std::get<std::shared_ptr<Bike>>(v);
            std::cout << *temp << '\n';
        }
        else
        {
            auto temp = std::get<std::shared_ptr<Car>>(v);
            std::cout << *temp << '\n';
        }
    }
}

float totalTaxExemptionAmount(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");
    float amount{0.0f};
    /* for(std::shared_ptr<Vehicle> c : data){
        if(typeid(*c)==typeid(Car)){
            std::shared_ptr<Car> ob = std::dynamic_pointer_cast<Car>(c);
            amount+=ob->TaxExemptionAmount();
        }
    } */
    amount = std::accumulate(data.begin(), data.end(), 0.0f,
                             [](float amount, std::variant<std::shared_ptr<Car>, std::shared_ptr<Bike>> &v)
                             {
                                 if (std::holds_alternative<std::shared_ptr<Bike>>(v))
                                 {
                                     auto temp = std::get<std::shared_ptr<Bike>>(v);
                                     return amount + temp->TaxExemptionAmount();
                                 }
                                 else
                                 {
                                     auto temp = std::get<std::shared_ptr<Car>>(v);
                                     return amount + temp->TaxExemptionAmount();
                                 }
                             });
    return amount;
}

void displayPriceAndBrand(Container &data, std::string regNo)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");

    auto itr = std::find_if(data.begin(), data.end(),
                            [&](const std::variant<std::shared_ptr<Car>, std::shared_ptr<Bike>> &v)
                            {
                                bool flag2 = false;
                                std::visit([&](auto &&val)
                                           { flag2 = val->registrationNumber() == regNo; },v);
                                return flag2;
                            });
    std::visit([](auto &&v)
               { std::cout << v->price() << " " << v->brand(); },
               *itr);
}

void firstAndLastObjectServicingCost(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is Empty");

    std::visit([](auto &&v)
               { std::cout << "First Object ServicingCost : " << v->CalculateServicingCost(); },
               data.front());
    std::visit([](auto &&v)
               { std::cout << "\nLast Object ServicingCost : " << v->CalculateServicingCost(); },
               data.back());
}
