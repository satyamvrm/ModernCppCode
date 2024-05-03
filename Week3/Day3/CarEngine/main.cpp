#include <bits/stdc++.h>
#include "Car.h"
#include "Engine.h"
#include "CarType.h"
#include "Functionilities.h"
#include <future>
#include <thread>

/* Normal exception doesn't work with threads In threads we will use future exception */

int main()
{
    Container data,data2;
    std::thread t1(CreateObjects, std::ref(data));
    t1.join();

    try
    {
        //
        std::future<int> ans = std::async(totalHorsePower, std::ref(data));
        std::future<float> result = std::async(avgEngineTorque, std::ref(data));
        std::future<std::string> model = std::async(findCarModelByID, std::ref(data2), "c101");
        std::future<bool> flag = std::async(isAllCarAbove700K, std::ref(data));
        std::future<Engine *> e = std::async(enginePointerToMinPrice, std::ref(data));

        std::cout << "Total horse power is " << ans.get() << '\n';
        std::cout << "\nAverage Value is " << result.get() << '\n';
        std::cout << "\nModel for give id found " << model.get() << '\n';
        if (flag.get())
        {
            std::cout << "\nAll are above 7 lacs";
        }
        else
        {
            std::cout << "\nSome are below 7 lacs";
        }
        std::cout << "\nEngine Found : " << *e.get() << "\n";
        DeleteObjects(data);
    }
    catch (std::future_error &ex)
    {
        if (ex.code() == std::future_errc::no_state)
        {
            std::cout << "Missing input\n"
                      << "\n";
        }
        if (ex.code() == std::future_errc::broken_promise)
        {
            std::cout << "Broken promise\n";
        }
    }
    return 0;
}