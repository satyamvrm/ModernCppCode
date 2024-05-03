#include "Functionalities.h"

#define line std::cout << "------------------------------------------------------------------------\n";

int main()
{
    Container1 data;
    Container2 data2;
    EngineVector e;
    createObject(data, e);
    createObject(data2, e);
    line;
    displayObject(data);
    line;
    displayObject(data2);

    std::future<std::map<std::string, CarPtr>> t = std::async(allCarsWithIds, std::ref(data));
    std::future<std::map<std::string, BikePtr>> t2 = std::async(allBikesWithIds, std::ref(data));
    std::map<std::string, BikePtr> result2;
    try
    {
        std::map<std::string, CarPtr> result = t.get();
        line;
        for (auto a : result)
        {
            std::cout << a.first << '\t' << *a.second << '\n';
        }
        result2 = t2.get();
        line;
        for (auto a : result2)
        {
            std::cout << a.first << '\t' << *a.second << '\n';
        }
        Container2 result3 = mapToPQ(result2);
        line;
        displayObject(result3);
    }
    catch (Exception &e)
    {
        if (e.ErrorCode() == std::future_errc::broken_promise)
            std::cout << e.what() << '\t' << "Broken Promis" << '\n';
        if (e.ErrorCode() == std::future_errc::no_state)
            std::cout << e.what() << '\t' << "NO State" << '\n';
    }
    line;
}