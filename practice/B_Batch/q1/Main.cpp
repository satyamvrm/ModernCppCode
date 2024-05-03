#include "Functionalities.h"

int main()
{
    Container data, data2;

    std::cout << "-------------------------------------------------------------------\n";
    createObject(data);
    display(data);

    std::cout << "-------------------------------------------------------------------\n";

    try
    {
        std::optional<std::list<CarPtr>> result1;
        result1 = firstNinstance(data, 2);
        if (result1.has_value())
            for (auto c : result1.value())
                std::cout << *c << '\n';

        std::cout << "-------------------------------------------------------------------\n";

        std::cout << "Count above 2.7 : " << countAboveThreshhold(data) << '\n';

        std::cout << "-------------------------------------------------------------------\n";

        std::cout << "Top speed of Car  : " << speedOfCar(data, "C-105") << '\n';

        std::cout << "-------------------------------------------------------------------\n";

        std::function<bool(CarPtr)> fn = [](CarPtr c) -> bool
        { return c->platform() == Platform::IC_BASED; };
        std::optional<Container>
            result2 = satisfiedCars(data, fn);
        if (result2.has_value())
            for (auto c : result2.value())
                std::cout << *c << '\n';
        std::cout << "-------------------------------------------------------------------\n";
        std::cout << "At least one : " << std::boolalpha << atleastOne(data) << '\n';
    }

    catch (const EmptyDataContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
}