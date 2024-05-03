#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <list>
#include <algorithm>
#include <variant>

// using AccountPtr = std::shared_ptr<Account>;
using SavingsAccountPtr = std::shared_ptr<SavingsAccount>;
using CurrentAccountPtr = std::shared_ptr<CurrentAccount>;
using AccountPtr = std::variant<SavingsAccountPtr, CurrentAccountPtr>;
using Container = std::list<AccountPtr>;

void createObjects(Container &data);
void displayObjects(Container &data);

bool allSavingsDebit(Container &data);

std::string MaxAccoutBalance(Container &data);

std::shared_ptr<DebitCard> CardInfo(Container &data, std::string id);

#endif // FUNCTIONALITIES_H
