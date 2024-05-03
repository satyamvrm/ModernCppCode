#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include "Gender.h"
#include "Account.h"

class CustomerAccount : public Account
{
private:
    std::string _fullName;
    Gender _customerGender;

public:
    CustomerAccount()=delete;
    CustomerAccount(const CustomerAccount&)=delete;
    CustomerAccount(const CustomerAccount&&)=delete;
    CustomerAccount &operator=(const CustomerAccount&) = delete;
    CustomerAccount &operator=(const CustomerAccount&&) = delete;
    ~CustomerAccount() = default;

    CustomerAccount(std::string name, std::string fname, Gender gType);

    std::string fullName() const { return _fullName; }
    void setFullName(const std::string &fullName) { _fullName = fullName; }

    Gender customerGender() const { return _customerGender; }
    void setCustomerGender(const Gender &customerGender) { _customerGender = customerGender; }

    friend std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs);

    void RegisterAccount() override;
};

#endif // CUSTOMER_H
