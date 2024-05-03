#include "Operations.h"
#include <future>

int main()
{
    std::unique_ptr<Operations> &ptr = Operations::getInstance();

    // ptr->createObject();
    std::future<void> t = std::async(&Operations::createObject, ptr.get());
    t.get();
    std::cout << "---------------------------------------------------\n";
    std::future<void> t1 = std::async(&Operations::display, ptr.get());
    t1.get();
    std::cout << "---------------------------------------------------\n";
    std::future<std::vector<std::reference_wrapper<Engine>>> result = std::async(&Operations::ReturnEngineReferance, ptr.get());
    for (auto r : result.get())
    {
        std::cout << r << '\n';
    }
    std::cout << "---------------------------------------------------\n";
    std::cout << "All abovr 120 : " << std::boolalpha << ptr->allAbove() << '\n';
    std::cout << "---------------------------------------------------\n";
    float temp = 140000.0f;
    std::future<int> t2 = std::async(&Operations::avgHorsepower, ptr.get(), std::ref(temp));
    std::cout << "Avg HP : " << t2.get() << '\n';
    std::cout << "---------------------------------------------------\n";
    std::future<EngineType> t3 = std::async(&Operations::findEngineType,ptr.get(),"C-101");
    std::cout << "Engine Type of C-101 : " << displayEnum(t3.get()) << '\n';
    std::cout << "---------------------------------------------------\n";
    std::future<std::reference_wrapper<Engine>> t4 = std::async(&Operations::highestTorque,ptr.get());
    std::cout << "Engine : " << t4.get() << '\n';
}