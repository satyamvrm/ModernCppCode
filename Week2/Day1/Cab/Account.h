#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
class Account
{
private:
    static unsigned long counter;
    unsigned long _id;
    std::string _username;
public:
    Account()=delete;
    Account(const Account&)=delete;
    Account(const Account&&)=delete;
    Account &operator=(const Account&) = delete;
    Account &operator=(const Account&&) = delete;
    ~Account() = default;

    virtual void RegisterAccount() = 0;

    explicit Account(std::string name);

    std::string username() const { return _username; }
    void setUsername(const std::string &username) { _username = username; }

    unsigned long id() const { return _id; }
 
    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
