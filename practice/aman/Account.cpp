#include "Account.h"
std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "AccountID: " << rhs._accountID
       << "\nTransactions:\n";
    for (auto &i : rhs._transactions)
        os << *i << '\n';
    os << "AccountBalance: " << rhs._accountBalance;
    return os;
}

Account::Account(std::string id, TransactionList list)
    : _accountID{id}, _transactions{list}
{
    for(auto t : list){
        _accountBalance+=t->transactionAmount();
    }
}