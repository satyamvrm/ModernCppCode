#include "Functionalities.h"
std::mutex mt;
void createObject(Conatainer &data)
{
    data.push_back(std::make_shared<Account>(
        "A-101",
        std::vector<std::shared_ptr<Transaction>>{
            std::make_shared<Transaction>("t-101", 100, TransactionType::CARD),
            std::make_shared<Transaction>("t-102", 100, TransactionType::UPI),
            std::make_shared<Transaction>("t-103", -100, TransactionType::CASH)}));

    data.push_back(std::make_shared<Account>(
        "A-102",
        std::vector<std::shared_ptr<Transaction>>{
            std::make_shared<Transaction>("t-101", 110, TransactionType::CARD),
            std::make_shared<Transaction>("t-102", 120, TransactionType::UPI),
            std::make_shared<Transaction>("t-103", 130, TransactionType::CASH)}));
    data.push_back(std::make_shared<Account>(
        "A-103",
        std::vector<std::shared_ptr<Transaction>>{
            std::make_shared<Transaction>("t-101", 120, TransactionType::CARD),
            std::make_shared<Transaction>("t-102", 110, TransactionType::UPI),
            std::make_shared<Transaction>("t-103", 140, TransactionType::CASH)}));
    data.push_back(std::make_shared<Account>(
        "A-104",
        std::vector<std::shared_ptr<Transaction>>{
            std::make_shared<Transaction>("t-101", 15000, TransactionType::CARD),
            std::make_shared<Transaction>("t-102", 1300, TransactionType::UPI),
            std::make_shared<Transaction>("t-103", 1200, TransactionType::CASH)}));
}

void displayObjects(Conatainer &data)
{
    for (auto i : data)
    {
        std::cout << *i << "\n\n";
    }
}

int countTransactionOfGivenType(Conatainer &data, TransactionType type)
{
    int count{0};
    for (auto a : data)
    {
        for (auto t : a->transactions())
        {
            if (t->transactionType() == type)
                count++;
        }
    }
    return count;
}

float totalTransctionAmunt(Conatainer &data)
{
    float amount{0.0f};
    amount = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float val, std::shared_ptr<Account> a)
        {
            return val += a->accountBalance();
        });
    return amount;
}

std::string findMaxAccountBalanceID(Conatainer &data)
{
    std::shared_ptr<Account> temp = data.front();
    for (auto i : data)
    {
        if (i->accountBalance() > temp->accountBalance())
            temp = i;
    }
    return temp->accountID();
}

Conatainer AccountAboveThreshold(Conatainer &data, float amount)
{
    Conatainer result;
    for (auto i : data)
    {
        if (i->accountBalance() > amount)
        {
            result.push_back(i);
        }
    }
    return result;
}

std::string nthTransectionID(Conatainer &data, int n, std::string id)
{
    std::string temp;
    for (auto i : data)
    {
        if (i->accountID() == id)
        {
            temp = i->transactions()[n]->transationId();
        };
    }
    return temp;
}

float averageTransactionAmount(Conatainer &data, std::string id)
{
    float amount{0}, count{0};
    for (auto i : data)
    {
        if (i->accountID() == id)
        {
            for (auto t : i->transactions())
            {
                amount += t->transactionAmount();
                count++;
            }
        }
    }
    return amount / count;
}

void balanceInterestAmount(Conatainer &data)
{
    float sum{0};
    for (auto i : data)
    {
        if (i->accountBalance() > 10000)
            sum += i->accountBalance() * 0.04;
        else
            sum += 0;
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "The total intrest : " << sum << '\n';
}

bool isValidAccount(Conatainer &data)
{
    bool result{false};
    for (auto i : data)
    {
        if (i->accountBalance() > 10000 && i->transactions().size() >= 3)
        {
            for (auto t : i->transactions())
            {
                if (t->transactionAmount() < 500)
                    break;
                result = true;
            }
        }
        std::lock_guard<std::mutex> lg(mt);
        std::cout<<"Accout : "<<i->accountID()<<" is valid "<<std::boolalpha<<result<<"\n";
    }
    return result;
}
