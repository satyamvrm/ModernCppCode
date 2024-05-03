#ifndef TRANSATION_H
#define TRANSATION_H

#include<iostream>
#include "TransactionType.h"

class Transaction
{
private:
    std::string _transationId;
    float _transactionAmount;
    TransactionType _transactionType;
    
public:
    //default constructor disabled
    Transaction()=delete;
    //default copy constructor disabled
    Transaction(const Transaction&) = delete;
    // default move constructor disabled 
    Transaction(const Transaction&&) = delete;
    // default assignment operator disabled 
    Transaction &operator=(const Transaction&) = delete; 
    // default move operator disabled
    Transaction &operator=(const Transaction&&) = delete; 
    // default distructor enabled 
    ~Transaction()=default;

    Transaction(std::string id, float amount, TransactionType type);

    std::string transationId() const { return _transationId; }
    void setTransationId(const std::string &transationId) { _transationId = transationId; }

    float transactionAmount() const { return _transactionAmount; }
    void setTransactionAmount(float transactionAmount) { _transactionAmount = transactionAmount; }

    TransactionType transactionType() const { return _transactionType; }
    void setTransactionType(const TransactionType &transactionType) { _transactionType = transactionType; }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);

};
std::string displayEnumValue(TransactionType t);
#endif // TRANSATION_H
