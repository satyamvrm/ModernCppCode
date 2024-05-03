#include "Functionalities.h"
#include <future>

#define line(msg) std::cout << "------------------------------------------" #msg "------------------------------------------------\n"

int main()
{
    Container data;
    line();
    createObjects(data);
    std::future<void> t1 = std::async(displayObjects, std::ref(data));
    std::future<Container> t2 = std::async(CarLessThan600K, std::ref(data));
    std::future<float> t3 = std::async(averagePriceOfEvCar, std::ref(data));
    std::future<int> t4 = std::async(countOfEvCar, std::ref(data), EPowerType::HYBRID);
    std::future<std::string> t5 = std::async(findBrandNameById, std::ref(data), "C-102");
    std::future<std::unordered_set<BatteryType>> t6 = std::async(findUniqueBatteryType, std::ref(data));
    std::future<bool> t7 = std::async(atLeastOneAbove60K, std::ref(data));
    try
    {
        t1.get();
        line();
        Container result = t2.get();
        displayObjects(result);
        line();
        std::cout << "Average Price of EvCars : " << t3.get() << '\n';
        line();
        std::cout << "Count of EvCar with Hybrid engine type : " << t4.get() << '\n';
        line();
        std::cout << "Brand Name of C-102 : " << t5.get() << '\n';
        line();
        std::unordered_set<BatteryType> result2 = t6.get();
        std::cout << "Unique Battery Types : " << '\n';
        for (auto c : result2)
            std::cout << '\t' << (displayEnum(c)) << '\n';
        line();
        std::cout << "Any of the car above 60K : " << std::boolalpha << t7.get() << '\n';
        line(Done);
    }
    catch (Exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}