#include "CurrentAccount.h"
std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs)
{
    os << static_cast<const Account &>(rhs)
       << " _isLoanApplied: " << std::boolalpha <<rhs._isLoanApplied;
    return os;
}

CurrentAccount::CurrentAccount(std::string accNo, float balance, std::string holderName, std::shared_ptr<DebitCard> debitCard, bool loan)
    : Account(accNo, balance, holderName, debitCard)
{
    _isLoanApplied = loan;
}

float CurrentAccount::CalculateAnnualCharges()
{
    return 800.0f;
}