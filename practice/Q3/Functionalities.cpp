#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(std::make_shared<EvCar>(101, ChassisType::LADDER, BatteryType::LI_ION, 400));
    data.push_back(std::make_shared<EvCar>(102, ChassisType::TUBULAR, BatteryType::NI_CAD, 440));
    data.push_back(std::make_shared<ICECar>(103, ChassisType::LADDER, FuelType::DIESEL, 20));
    data.push_back(std::make_shared<ICECar>(104, ChassisType::TUBULAR, FuelType::PETROL, 25));
}

void NInstances(Container &data, ClassType type, int n)
{
    if (data.empty())
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);
    Container result(data.size());
    auto itr = std::copy_if(data.begin(), data.end(), result.begin(),
                            [&](VType &v)
                            {
                                bool flag = false;
                                if (type == ClassType::EvCar_TYPE)
                                {
                                    if (std::holds_alternative<EvCarPointer>(v))
                                        flag = true;
                                }
                                else
                                {
                                    if (std::holds_alternative<ICECarPointer>(v))
                                        flag = true;
                                }
                                return flag;
                            });
    result.resize(std::distance(result.begin(), itr));
    for (VType &c : result)
    {
        std::visit([](auto &&a)
                   { std::cout << *a << '\n'; },
                   c);
    }
}

bool TankCapacity(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);

    bool flag = std::all_of(data.begin(), data.end(),
                            [](VType &v)
                            {
                                if (std::holds_alternative<ICECarPointer>(v))
                                {
                                    ICECarPointer temp = std::get<ICECarPointer>(v);
                                    if (temp->fuelTankCapacity() > 30)
                                        return true;
                                    else
                                        return false;
                                }
                                else
                                    return false;
                            });
    return flag;
}

void CountICECar(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);
    int count{0};
    count = std::count_if(data.begin(), data.end(),
                          [](VType &c)
                          {
                              if (std::holds_alternative<ICECarPointer>(c))
                                  return true;
                              else
                                  return false;
                          });
    std::cout << "Count :- " << count << '\n';
}

Container BatteryThreshold(Container &data, float threshold)
{
    if (data.empty())
        throw EmptyContainerException("Data is empty", std::future_errc::no_state);

    Container result(data.size());
    auto itr = std::copy_if(data.begin(), data.end(), result.begin(),
                            [&](VType &c)
                            {
                                if (std::holds_alternative<EvCarPointer>(c))
                                {
                                    EvCarPointer temp = std::get<EvCarPointer>(c);
                                    if (temp->batteryCapacity() > threshold)
                                        return true;
                                    else
                                        return false;
                                }
                                else
                                    return false;
                            });
    result.resize(std::distance(result.begin(), itr));
    return result;
}

void Display(Container &data)
{
    auto ans = std::accumulate(data.begin(), data.end(), 0.0f, [&](float a, const VType &v)
                               {

        if(std::holds_alternative<EvCarPointer>(v))
        {
            EvCarPointer ev = std::get<EvCarPointer>(v);
            if (ev->batteryCapacity() < 20 && ev->batteryCapacity() > 50)
            {
                throw BatteryCapacityExceed("Battery Capacity exceeds");
            }
            return a + ev->batteryCapacity();
        } else return a;});
    std::cout << "Battery Capacity is : " << ans << std::endl;
}

void DisplayNth(Container &data, int n)
{
    std::visit([](auto &&args)
               { std::cout << *args; },
               data[n]);

    std::cout << "\n";
}
