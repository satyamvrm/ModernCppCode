#include "Functionalities.h"

void createObjects(Container &data, InvoiceContainer &data2)
{
    data2.push_back(std::make_shared<Invoice>("A101", 12000, PaymentType::ONLINE));
    data2.push_back(std::make_shared<Invoice>("A102", 15000, PaymentType::CASH));
    data.emplace_back(std::make_shared<Bill>(101, *data2[0]));
    data.emplace_back(std::make_shared<Bill>(102, *data2[1]));
    data.emplace_back(std::make_shared<Bill>(103, *data2[0]));
    data.emplace_back(std::make_shared<Bill>(104, *data2[1]));
}

void displayObjects(Container &data)
{
    for (auto c : data)
    {
        std::cout << *c << '\n';
    }
}

std::function<void(Container &, std::string)> fns1 = [](Container &data, std::string str)
{
    for (auto c : data)
    {
        if (c->invoice().get().invoiceNumber() == str) std::cout<<c->invoice()<<'\n';
    }
};

std::function<int(Container&)> fns2 = [](Container& data){
    int sum{0};
    for(auto c : data){
        if(c->invoice().get().amount()>1300) sum+=c->invoice().get().amount();
    }
    return sum;
};
