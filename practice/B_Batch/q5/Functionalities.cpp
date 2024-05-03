#include "Functionalities.h"

void createObject(VehicleContainer &data)
{
    data.emplace_back(std::make_shared<Vehicle>("V-101", 10.0f, VehicleCategory::GOVERNMENT, TransmissionType::AMT, 10, true));
    data.emplace_back(std::make_shared<Vehicle>("V-102", 20.0f, VehicleCategory::PRIVATE, TransmissionType::AUTOMATC, 20, false));
    data.emplace_back(std::make_shared<Vehicle>("V-103", 30.0f, VehicleCategory::GOVERNMENT, TransmissionType::AMT, 30, true));
    data.emplace_back(std::make_shared<Vehicle>("V-104", 40.0f, VehicleCategory::PUBLIC, TransmissionType::MANUAL, 40, false));
    data.emplace_back(std::make_shared<Vehicle>("V-105", 50.0f, VehicleCategory::PRIVATE, TransmissionType::MANUAL, 50, true));
}

void displayObject(VehicleContainer &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    for (auto c : data)
    {
        std::cout << *c << '\n';
    }
}

std::optional<std::vector<TransmissionType>> lastNinstance(VehicleContainer &data, int n)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::vector<TransmissionType> result;
    std::for_each_n(
        data.rbegin(),
        n,
        [&](const VehiclePtr &v)
        {
            result.push_back(v->type());
        });
    if (result.empty())
        return std::nullopt;
    return result;
}

std::optional<TransmissionType *> lastNinstanceC(VehicleContainer &data, int n)
{
    if (data.empty())
        throw Exception("Data is Empty!");

    TransmissionType* arr = new TransmissionType[n];
    TransmissionType* t = arr;
    std::for_each_n(
        data.begin(),
        n,
        [&](const VehiclePtr& v){
            *t = v->type();
            t++;
        }
    );
    if(arr==nullptr) return std::nullopt;
    return arr;
}

PriorityQueue sortedByFunction(const VehicleContainer &data, const fn &f)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    PriorityQueue result(f);
    for (auto d : data)
    {
        result.push(d);
    }
    return result;
}

std::unordered_set<float> uniquePrice(VehicleContainer &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::unordered_set<float> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const VehiclePtr &v)
        { result.insert(v->price()); });
    return result;
}

std::unordered_map<std::string, VehicleCategory> IdCategoryMap(VehicleContainer &data, int n)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::unordered_map<std::string, VehicleCategory> result;
    std::for_each_n(
        data.begin(),
        n,
        [&](const VehiclePtr &v)
        {
            result.emplace(v->id(), v->category());
        });
    return result;
}

// 6
int *bootSpaceList(VehicleContainer &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    int *arr = new int[data.size()];
    int *t = arr;
    for (auto c : data)
    {
        *arr = c->bootSpace();
        arr++;
    }
    return t;
}

VehicleContainer insuredVehicels(VehicleContainer &data)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    VehicleContainer result(data.size());
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),
        [&](const VehiclePtr &v)
        {
            return v->isInsured();
        });
    result.resize(std::distance(result.begin(), itr));
    return result;
}

std::vector<unsigned int> unaryBootSpace(VehicleContainer &data, std::function<int(VehiclePtr &)> fn)
{
    if (data.empty())
        throw Exception("Data is Empty!");
    std::vector<unsigned int> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](VehiclePtr &v)
        {
            result.push_back(fn(v));
        });
    return result;
}
