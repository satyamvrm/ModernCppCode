#include "Account.h"

unsigned long Account::counter = 90000;

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "_id: " << rhs._id
       << " _username: " << rhs._username;
    return os;
}

Account::Account(std::string name)
    : _username{name}, _id{++counter}
{
}