#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transation.h"
#include <vector>
#include<memory>

using TransactionList = std::vector<std::shared_ptr<Transaction>>;

class Account
{
private:
    std::string _accountID;
    TransactionList _transactions;
    float _accountBalance{0};

public:
    // default constructor disabled
    Account() = delete;
    // default copy constructor disabled
    Account(const Account &) = delete;
    // default move constructor disabled
    Account(const Account &&) = delete;
    // default assignment operator disabled
    Account &operator=(const Account &) = delete;
    // default move operator disabled
    Account &operator=(const Account &&) = delete;
    // default distructor enabled
    ~Account() = default;

    Account(std::string id, TransactionList list);

    std::string accountID() const
    {
        return _accountID;
    }
    void setAccountID(const std::string &accountID) { _accountID = accountID; }

    float accountBalance() const { return _accountBalance; }
    void setAccountBalance(float accountBalance) { _accountBalance = accountBalance; }

    TransactionList transactions() const { return _transactions; }
    void setTransactions(const TransactionList &transactions) { _transactions = transactions; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
