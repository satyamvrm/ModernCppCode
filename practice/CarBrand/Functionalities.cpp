#include "Functionalities.h"

void createObjects(Container &brands, CarContainer &Cars)
{
    Cars.push_back(std::make_shared<Car>(1001, 2023));
    Cars.push_back(std::make_shared<Car>(1002, 2024));
    Cars.push_back(std::make_shared<Car>(1003, 2023));
    Cars.push_back(std::make_shared<Car>(1004, 2022));
    Cars.push_back(std::make_shared<Car>(1005, 2021));
    Cars.push_back(std::make_shared<Car>(1006, 2022));
    Cars.push_back(std::make_shared<Car>(1007, 2024));
    Cars.push_back(std::make_shared<Car>(1008, 2024));
    Cars.push_back(std::make_shared<Car>(1009, 2022));

    brands.push_back(std::make_shared<Brand>("Honda", std::vector<std::reference_wrapper<carPtr>>{Cars[0], Cars[1], Cars[2]}));
    brands.push_back(std::make_shared<Brand>("Farrari", std::vector<std::reference_wrapper<carPtr>>{Cars[3], Cars[4], Cars[5]}));
    brands.push_back(std::make_shared<Brand>("BMW", std::vector<std::reference_wrapper<carPtr>>{Cars[6], Cars[7], Cars[8]}));
}

void display(Container &data)
{
    for (auto a : data)
    {
        std::cout << *a.get() << "\n\n";
    }
}

