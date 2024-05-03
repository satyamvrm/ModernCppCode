#include "Functionalities.h"

void createObjects(Container &data)
{
    data.emplace_back(std::make_shared<SavingsAccount>("S-101", 1200, "A", nullptr, 1000));
    data.emplace_back(std::make_shared<SavingsAccount>("S-102", 1500, "B", std::make_shared<DebitCard>(123456789123, 112), 1000));
    data.emplace_back(std::make_shared<SavingsAccount>("S-103", 1700, "C", nullptr, 1000));
    data.emplace_back(std::make_shared<SavingsAccount>("S-104", 2200, "d", std::make_shared<DebitCard>(678912389123, 189), 1000));
    data.emplace_back(std::make_shared<CurrentAccount>("C-101", 12000, "P", nullptr, false));
    data.emplace_back(std::make_shared<CurrentAccount>("C-102", 12200, "Q", std::make_shared<DebitCard>(123456789123, 122), false));
    data.emplace_back(std::make_shared<CurrentAccount>("C-103", 12300, "R", std::make_shared<DebitCard>(789123123456, 537), false));
    data.emplace_back(std::make_shared<CurrentAccount>("C-104", 15000, "S", nullptr, false));
}

void displayObjects(Container &data)
{
    for (auto d : data)
    {
        // if (SavingsAccountPtr temp = std::dynamic_pointer_cast<SavingsAccount>(d))
        //     std::cout << *temp.get() << '\n';
        // if (CurrentAccountPtr temp = std::dynamic_pointer_cast<CurrentAccount>(d))
        //     std::cout << *temp.get() << '\n';
        std::visit([&](auto &&val)
                   { std::cout << *val << '\n'; },
                   d);
    }
}

bool allSavingsDebit(Container &data)
{
    return std::all_of(
        data.begin(),
        data.end(),
        [](const AccountPtr &a)
        {
            // if (SavingsAccountPtr t = std::dynamic_pointer_cast<SavingsAccount>(a))
            //     return t->debitCard() != nullptr;
            bool result;
            if (std::holds_alternative<SavingsAccountPtr>(a))
            {
                auto c = std::get<SavingsAccountPtr>(a);
                result = c->debitCard() != nullptr;
            }
            return result;
        });
}

std::string MaxAccoutBalance(Container &data)
{
    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](const AccountPtr &a1, const AccountPtr &a2)
        {
            // return a1->balance() < a2->balance();
            auto t1 = std::visit([&](auto &&val)
                                 { return val->balance(); },
                                 a1);
            auto t2 = std::visit([&](auto &&val)
                                 { return val->balance(); },
                                 a2);
            return t1 < t2;
        });
    // return itr->get()->accNo();
    std::string temp = std::visit([&](auto &&val)
                                  { return val->accNo(); },
                                  *itr);
    return temp;
}

std::shared_ptr<DebitCard> CardInfo(Container &data, std::string id)
{
    std::shared_ptr<DebitCard> temp = nullptr;
    std::for_each(
        data.begin(),
        data.end(),
        [&](const AccountPtr &a)
        {
            // if (a->accNo() == id)
            //     temp = a->debitCard();
            std::visit([&](auto &&val)
                       {if(val->accNo()==id) temp=val->debitCard(); },
                       a);
        });
    return temp;
}
