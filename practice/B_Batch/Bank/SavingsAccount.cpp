#include "SavingsAccount.h"
std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs)
{
    os << static_cast<const Account &>(rhs)
       << " _minimumBalance: " << rhs._minimumBalance;
    return os;
}

SavingsAccount::SavingsAccount(std::string accNo, float balance, std::string holderName, std::shared_ptr<DebitCard> debitCard, float minBal)
    : Account(accNo, balance, holderName, debitCard)
{
    _minimumBalance = minBal;
}

float SavingsAccount::CalculateAnnualCharges()
{
    if (debitCard() != nullptr)
        return 500.0f;
    return 100.0f;
}
