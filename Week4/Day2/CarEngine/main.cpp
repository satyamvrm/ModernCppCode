#include <bits/stdc++.h>
#include "Car.h"
#include "Engine.h"
#include "CarType.h"
#include "Functionilities.h"
#include <future>
#include <thread>

/* Normal exception doesn't work with threads In threads we will use future exception */

/* While working on a map each entry will be a pair and fetching one entry from the hash table is done by a function which mean the return as a rvalue so const is important */

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
        std::future<std::string> model = std::async(findCarModelByID, std::ref(data), "c101");
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
    }
    catch (std::runtime_error &e)
    {
        std::cout<<e.what()<<'\n';
    }
    return 0;
}