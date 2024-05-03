#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(
        std::make_shared<OnlinePayment>(
            "c101",
            "Phase III",
            "Phase I",
            100.0f,
            PaymentType::WALLET,
            1));
    data.push_back(
        std::make_shared<OnlinePayment>(
            "c102",
            "Phase I",
            "Bus Station",
            220.0f,
            PaymentType::CARD,
            2));
    data.push_back(
        std::make_shared<OnlinePayment>(
            "c103",
            "Phase III",
            "Airport",
            300.0f,
            PaymentType::UPI,
            3));
    data.push_back(
        std::make_shared<CashPayment>(
            "c104",
            "Phase III",
            "Phase I",
            100.0f,
            20));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw EmptyData("Data is Empty");
//     for (const auto c : data)
//     {
//         std::cout << *c << '\n';
//     }
/* 
    std::shared_ptr<Base> basePtr = std::make_shared<Derived>();
 
    // Perform dynamic_cast using std::dynamic_pointer_cast
    std::shared_ptr<Derived> derivedPtr = std::dynamic_pointer_cast<Derived>(basePtr);
 
    if (derivedPtr) {
        // dynamic_cast successful, derivedPtr now points to a Derived object
        derivedPtr->derivedFunction();
    } else {
        // dynamic_cast failed, basePtr does not point to a Derived object
    } */

    for(const auto c : data){
        if(typeid(*c)==typeid(CashPayment)){
            std::shared_ptr<CashPayment> ob = std::dynamic_pointer_cast<CashPayment>(c);
            if(ob) std::cout<<*ob<<'\n';
        }
        else{
            std::shared_ptr<OnlinePayment> ob = std::dynamic_pointer_cast<OnlinePayment>(c);
            if(ob) std::cout<<*ob<<'\n';
        }
    }
}

Pointer findBookingById(Container &data)
{
    if (data.empty())
        throw EmptyData("Data is Empty");
    float max = data.begin()->get()->calculateFair();
    for (auto const c : data)
    {
        if (c->calculateFair() > max)
            max = c->calculateFair();
    }
    for (const auto c : data)
    {
        if (max == c->calculateFair())
            return c;
    }
    return nullptr;
}

bool allAbove1000(Container &data)
{
    if (data.empty())
        throw EmptyData("Data is Empty");
    for (const auto c : data)
        if (c->calculateFair() < 1000)
            return false;
    return false;
}

Container nInstance(Container &data, int n)
{
    if (data.empty())
        throw EmptyData("Data is Empty");
    if (data.size() < n || n <= 0)
        throw EmptyData("Invalid Instance");
    Container newData;
    auto itr = data.end();
    int count{0};
    for (int i = data.size() - 1; i >= n; i--)
    {
        itr--;
        newData.push_back(*itr);
        // itr--;
    }
    return newData;
}
