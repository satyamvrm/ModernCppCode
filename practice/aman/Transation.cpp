#include "Transation.h"
std::ostream &operator<<(std::ostream &os, const Transaction &rhs)
{
    os << "_transationId: " << rhs._transationId
       << " _transactionAmount: " << rhs._transactionAmount
       << " _transactionType: " << displayEnumValue(rhs._transactionType);
    return os;
}

std::string displayEnumValue(TransactionType t)
{
    if (t == TransactionType::CARD)
        return "CARD";
    else if (t == TransactionType::CASH)
        return "CASH";
    else
        return "UPI";
}

Transaction::Transaction(std::string id, float amount, TransactionType type)
    : _transactionAmount{amount}, _transationId{id}, _transactionType{type}
{
}