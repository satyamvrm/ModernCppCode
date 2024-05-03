#include "Functionalities.h"

#define line std::cout << "------------------------------------------------------\n"

std::function<bool(const VehiclePtr &c1, const VehiclePtr &c2)> f = [](const VehiclePtr &c1, const VehiclePtr &c2) -> bool
{
    return c1->price() < c2->price();
};

void displayPQ(PriorityQueue pq)
{
    while (!pq.empty())
    {
        std::cout << *pq.top() << '\n';
        pq.pop();
    }
}

std::function<int(VehiclePtr &v)> fnc = [](VehiclePtr &v) -> int
{ return v->bootSpace() + 10; };

int main()
{
    VehicleContainer data;
    createObject(data);
    line;
    displayObject(data);
    // std::future<std::optional<std::vector<TransmissionType>>> t1 = std::async(lastNinstance, std::ref(data), 3);
    std::future<std::optional<TransmissionType *>> t1 = std::async(lastNinstanceC, std::ref(data), 3);
    std::future<std::unordered_set<float>> t3 = std::async(uniquePrice, std::ref(data));
    std::future<std::unordered_map<std::string, VehicleCategory>> t4 = std::async(IdCategoryMap, std::ref(data), 2);
    std::future<int *> t5 = std::async(bootSpaceList, std::ref(data));
    try
    {
        line;
        /* std::optional<std::vector<TransmissionType>> result = t1.get();
        std::cout << "Last N Instance : " << '\n';
        if (result.has_value())
        {
            for (auto u : result.value())
            {
                std::cout << '\t' << displayEnum(u) << '\n';
            }
        } */
        std::optional<TransmissionType *> result = t1.get();
        if (result.has_value())
        {
            TransmissionType *temp = result.value();
            for (int i = 0; i < 3; i++)
            {
                std::cout  << '\t' << displayEnum(temp[i]);
            }
        }
        else{
            std::cout<<"No value"<<'\n';
        }
        std::cout<<'\n';

        line;
        PriorityQueue result2 = sortedByFunction(data, f);
        displayPQ(result2);
        line;
        std::unordered_set<float> result3 = t3.get();
        std::cout << "Unique Prices : " << '\n';
        for (auto a : result3)
            std::cout << '\t' << a;
        std::cout << '\n';
        line;
        std::unordered_map<std::string, VehicleCategory> result4 = t4.get();
        std::cout << "Key :\t Value" << '\n';
        for (auto c : result4)
        {
            std::cout << c.first << '\t' << displayEnum(c.second) << '\n';
        }
        line;
        int *result5 = t5.get();
        std::cout << "Array Of Boot Space : \n";
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << '\t' << result5[i];
        }
        std::cout << '\n';
        line;
        std::cout << "All Insured Vehicles : \n";
        VehicleContainer result7 = insuredVehicels(data);
        displayObject(result7);
        line;
        std::cout << "Function Applied :\n";
        std::vector<unsigned int> result8 = unaryBootSpace(data, fnc);
        for (auto c : result8)
        {
            std::cout << '\t' << c;
        }
        std::cout << '\n';
        line;
    }
    catch (Exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}