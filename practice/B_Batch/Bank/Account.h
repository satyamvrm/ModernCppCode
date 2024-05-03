#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <memory>
#include "DebitCard.h"

class Account
{
private:
    /* data */
    std::string _accNo;
    float _balance;
    std::string _holderName;
    std::shared_ptr<DebitCard> _debitCard;

public:
    Account() = delete;
    Account(const Account &) = delete;
    Account(Account &&) = delete;
    Account &operator=(const Account &) = delete;
    Account &operator=(Account &&) = delete;
    ~Account() = default;

    Account(
        std::string accNo,
        float balance,
        std::string holderName,
        std::shared_ptr<DebitCard> debitCard);

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    virtual float CalculateAnnualCharges() = 0;

    std::string accNo() const { return _accNo; }
    void setAccNo(const std::string &accNo) { _accNo = accNo; }

    float balance() const { return _balance; }
    void setBalance(float balance) { _balance = balance; }

    std::string holderName() const { return _holderName; }
    void setHolderName(const std::string &holderName) { _holderName = holderName; }

    std::shared_ptr<DebitCard> debitCard() const { return _debitCard; }
    void setDebitCard(const std::shared_ptr<DebitCard> &debitCard) { _debitCard = debitCard; }

};

#endif // ACCOUNT_H
