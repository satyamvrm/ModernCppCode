#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Account.h"
#include <algorithm>
#include <numeric>
#include <memory>
#include <thread>
#include <mutex>

using Conatainer = std::vector<std::shared_ptr<Account>>;

void createObject(Conatainer &data);
void displayObjects(Conatainer &data);

int countTransactionOfGivenType(Conatainer &data, TransactionType t);
float totalTransctionAmunt(Conatainer &data);

std::string findMaxAccountBalanceID(Conatainer &data);

Conatainer AccountAboveThreshold(Conatainer &data, float amount);

std::string nthTransectionID(Conatainer &data, int n, std::string id);

float averageTransactionAmount(Conatainer &data, std::string id);

void balanceInterestAmount(Conatainer &data);

bool isValidAccount(Conatainer &data);

#endif // FUNCTIONALITIES_H
