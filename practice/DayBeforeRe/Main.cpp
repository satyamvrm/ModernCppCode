#include "Functionalities.h"
#include <future>

#define line std::cout << "---------------------------------------------------------------\n";

int main()
{
    Container data;
    // std::future<void(Container &)> t = std::async(createObject, std::ref(data));
    std::future<void> t = std::async(createObject, std::ref(data));
    t.get();
    std::future<void> t1 = std::async(displayObjects, std::ref(data));
    line;
    t1.get();
    line;
    std::future<TransmissionType *> t2 = std::async(lastNtransmissionType, std::ref(data), 2);
    std::future<PQContainer> t3 = std::async(dataInPQ, std::ref(data), [](const VehiclePtr &v1, const VehiclePtr &v2)
                                             { return v1->price() < v2->price(); });
    std::future<std::unordered_set<float>> t4 = std::async(uniquePrice, std::ref(data));
    std::future<std::unordered_map<std::string, Category>> t5 = std::async(nIdCategoryPair, std::ref(data), 3);
    std::future<int *> t6 = std::async(bootSpaceValues, std::ref(data));
    std::future<std::vector<float>> t7 = std::async(unararyFunction, std::ref(data),std::nullopt);//, [](const VehiclePtr &v){ return v->price() + 1000; });
    std::future<std::optional<Container>> t8 = std::async(isInsured, std::ref(data));

    try
    {
        TransmissionType *result = t2.get();
        std::cout << "Last N Transmission Types :- \n";
        for (int i = 0; i < 2; i++)
        {
            std::cout << '\t' << displayEnum(result[i]) << '\n';
        }
        line;
        PQContainer result2 = t3.get();
        Display(result2);
        line;
        std::unordered_set<float> result3 = t4.get();
        std::cout << "Unique Prices :- \n";
        for (auto i : result3)
            std::cout << '\t' << i << '\n';
        line;
        std::cout << "nID category pair :-\n";
        std::unordered_map<std::string, Category> result4 = t5.get();
        for (auto i : result4)
        {
            std::cout << i.first << '\t' << displayEnum(i.second) << '\n';
        }
        line;
        int *result5 = t6.get();
        std::cout << "Boot Space Value :- \n";
        for (int i = 0; i < data.size(); i++)
            std::cout << '\t' << result5[i] << '\n';
        line;

        // std::vector<float> result6 = t7.get();
        std::vector<float> result6 = unararyFunction(data);
        std::cout << "Uniary Operator :-\n";
        for (auto i : result6)
            std::cout << '\t' << i << '\n';
        line;

        std::optional<Container> result7 = t8.get();
        if (result7.has_value())
        {
            Container temp = result7.value();
            for (auto i : temp)
            {
                std::cout << *i << '\n';
            }
        }
        else
        {
            std::cout << "No Vehicle Have Insurance!\n";
        }
        line;
        delete [] result;
        delete [] result5;
    }
    catch (Exception &e)
    {
        std::cout << "Error :- " << e.what() << '\t' << "Error Code :- " << e.Code() << '\n';
    }

}