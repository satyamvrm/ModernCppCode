#ifndef INVOICE_H
#define INVOICE_H

#include<iostream>
#include "PaymentType.h"

class Invoice
{
private:
    std::string _invoiceNumber;
    float _amount;
    PaymentType _type;

public:
    //default constructor disabled
    Invoice()=default;
    //default copy constructor disabled
    Invoice(const Invoice&) = delete;
    // default move constructor disabled 
    Invoice(const Invoice&&) = delete;
    // default assignment operator disabled 
    Invoice &operator=(const Invoice&) = default; 
    // default move operator disabled
    Invoice &operator=(const Invoice&&) = delete; 
    // default distructor enabled 
    ~Invoice()=default;

    Invoice(std::string inNum, float amount, PaymentType type);

    std::string invoiceNumber() const { return _invoiceNumber; }
    void setInvoiceNumber(const std::string &invoiceNumber) { _invoiceNumber = invoiceNumber; }

    float amount() const { return _amount; }
    void setAmount(float amount) { _amount = amount; }

    PaymentType type() const { return _type; }
    void setType(const PaymentType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs);

    
};

#endif // INVOICE_H
