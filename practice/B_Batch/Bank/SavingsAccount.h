#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <ostream>

class SavingsAccount : public Account
{
private:
    /* data */
    float _minimumBalance;

public:
    SavingsAccount() = delete;
    SavingsAccount(const SavingsAccount &) = delete;
    SavingsAccount(SavingsAccount &&) = delete;
    SavingsAccount &operator=(const SavingsAccount &) = delete;
    SavingsAccount &operator=(SavingsAccount &&) = delete;
    ~SavingsAccount() = default;

    SavingsAccount(
        std::string accNo,
        float balance,
        std::string holderName,
        std::shared_ptr<DebitCard> debitCard,
        float minBal
    );

    virtual float CalculateAnnualCharges();

    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs);
};

#endif // SAVINGSACCOUNT_H
