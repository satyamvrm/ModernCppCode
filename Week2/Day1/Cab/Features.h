#ifndef FEATURES_H
#define FEATURES_H
#include <vector>
#include "Account.h"
#include "AccountType.h"
using AccountContainer = std::vector<Account *>;

class Features
{
private:
    /* data */
public:
    Features(/* args */) {}
    ~Features() {}
    // should accept reference of a container, an enum to decide type of account then accept input call the constructor and store pointer in accountCounter
    static void CreateAccount(AccountContainer& accounts, AccountType accType);

};

#endif // FEATURES_H
