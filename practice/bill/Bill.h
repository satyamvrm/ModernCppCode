#ifndef BILL_H
#define BILL_H

#include<functional>
#include <ostream>
#include "Invoice.h"

class Bill
{
private:
    int _billNumber;
    std::reference_wrapper<Invoice> _invoice;

public:
    //default constructor disabled
    Bill()=default;
    //default copy constructor disabled
    Bill(const Bill&) = delete;
    // default move constructor disabled 
    Bill(const Bill&&) = delete;
    // default assignment operator disabled 
    Bill &operator=(const Bill&) = default; 
    // default move operator disabled
    Bill &operator=(const Bill&&) = delete; 
    // default distructor enabled 
    ~Bill()=default;

    Bill(int billNum, std::reference_wrapper<Invoice> invoice);

    int billNumber() const { return _billNumber; }
    void setBillNumber(int billNumber) { _billNumber = billNumber; }

    std::reference_wrapper<Invoice> invoice() const { return _invoice; }
    void setInvoice(const std::reference_wrapper<Invoice> &invoice) { _invoice = invoice; }

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs);
    
};

#endif // BILL_H
