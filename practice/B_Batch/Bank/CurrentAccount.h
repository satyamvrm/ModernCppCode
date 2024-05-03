#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
#include <ostream>

class CurrentAccount : public Account
{
private:
    /* data */
    bool _isLoanApplied;

public:
    CurrentAccount(/* args */) = delete;
    CurrentAccount(CurrentAccount &) = delete;
    CurrentAccount(CurrentAccount &&) = delete;
    CurrentAccount &operator=(CurrentAccount &) = delete;
    CurrentAccount &operator=(CurrentAccount &&) = delete;
    ~CurrentAccount() = default;

    CurrentAccount(
        std::string accNo,
        float balance,
        std::string holderName,
        std::shared_ptr<DebitCard> debitCard,
        bool loan);

    virtual float CalculateAnnualCharges();

    friend std::ostream &operator<<(std::ostream &os, const CurrentAccount &rhs);
};

#endif // CURRENTACCOUNT_H
