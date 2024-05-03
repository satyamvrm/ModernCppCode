#include "Functionalities.h"
std::mutex mt;
void createObject(Container &data)
{
    data.push_back(std::make_shared<Vehicle>("C-101", 10, Category::GOVT, TransmissionType::AUTOMATIC, 10, true));
    data.push_back(std::make_shared<Vehicle>("C-102", 20, Category::GOVT, TransmissionType::AMT, 20, true));
    data.push_back(std::make_shared<Vehicle>("C-103", 30, Category::PRIVATE, TransmissionType::AMT, 30, true));
    data.push_back(std::make_shared<Vehicle>("C-104", 40, Category::PRIVATE, TransmissionType::AUTOMATIC, 40, true));
    data.push_back(std::make_shared<Vehicle>("C-105", 40, Category::PUBLIC, TransmissionType::MANUAl, 50, true));
    data.push_back(std::make_shared<Vehicle>("C-106", 60, Category::PUBLIC, TransmissionType::MANUAl, 60, true));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    std::lock_guard<std::mutex> lg(mt);
    std::for_each(
        data.begin(),
        data.end(),
        [&](const VehiclePtr &v)
        {
            std::cout << *v << '\n';
        });
}

TransmissionType *lastNtransmissionType(Container &data, int n)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    if (n < 0 || n > data.size())
        throw Exception("Invalid Number!", std::future_errc::broken_promise);
    TransmissionType *result = new TransmissionType[n];
    int i{0};
    std::for_each_n(
        data.rbegin(),
        n,
        [&](const VehiclePtr &v)
        {
            result[i++] = v->type();
        });
    return result;
}

PQContainer dataInPQ(Container &data, std::function<bool(const VehiclePtr &v1, const VehiclePtr &v2)> fn)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    PQContainer result(data.begin(), data.end(), fn);
    return result;
}

void Display(PQContainer data)
{

    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    while (!data.empty())
    {
        std::cout << *data.top() << '\n';
        data.pop();
    }
}

std::unordered_set<float> uniquePrice(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    std::unordered_set<float> result;
    std::for_each(data.begin(), data.end(), [&](const VehiclePtr &v)
                  { result.emplace(v->price()); });
    return result;
}

std::unordered_map<std::string, Category> nIdCategoryPair(Container &data, int n)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    if (n <= 0 || n > data.size())
        throw Exception("Invalid Input!", std::future_errc::broken_promise);
    std::unordered_map<std::string, Category> result;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const VehiclePtr &v)
        {
            result.emplace(v->id(), v->vCategory());
        });
    return result;
}

int *bootSpaceValues(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    int *result = new int[data.size()];
    int i{0};
    std::for_each(
        data.begin(),
        data.end(),
        [&](const VehiclePtr &v)
        {
            result[i++] = v->bootSpace();
        });
    return result;
}

std::vector<float> unararyFunction(Container &data, std::optional<std::function<float(const VehiclePtr &v)>> fn)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);

    std::vector<float> result;
    if (fn.has_value())
        std::for_each(
            data.begin(),
            data.end(),
            [&](const VehiclePtr &v)
            {
                result.push_back(fn.value()(v));
            });
    else
        std::for_each(
            data.begin(),
            data.end(),
            [&](const VehiclePtr &v)
            {
                result.push_back(v->price()*2.0);
            });
    return result;
}

std::optional<Container> isInsured(Container &data)
{
    if (data.empty())
        throw Exception("Data is Empty!", std::future_errc::no_state);
    Container result(data.size());
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),
        [&](const VehiclePtr &v)
        {
            return !v->insured();
        });
    result.resize(std::distance(result.begin(), itr));
    if (result.empty())
        return std::nullopt;
    return result;
}
