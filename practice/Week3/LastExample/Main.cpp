#include "Functionalities.h"

int main()
{
    Container data;
    std::shared_ptr<Insurance> i1 = std::make_shared<Insurance>("1", 1000.0f, InsuranceType::Rgular);
    data.emplace_back(std::make_shared<Car>(101, 1, VehicleType::Commercial, std::make_shared<Insurance>("1", 1000.0f, InsuranceType::Rgular), CarType::Hatchback, 50000.0f, "Black"));
    data.emplace_back(std::make_shared<Car>(102, 2023, VehicleType::Private, std::make_shared<Insurance>("1", 1000.0f, InsuranceType::Rgular), CarType::SUV, 54000.0f, "Black"));

    try
    {
        std::optional<Container> result = carAboveThreshold(data, 52000);
        if (result.has_value())
        {
            for (auto c : result.value())
            {
                std::cout << c << '\n';
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}