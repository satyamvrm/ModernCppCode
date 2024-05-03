#include "Invoice.h"

std::string displayType(PaymentType t){
    if(t==PaymentType::ONLINE) return "Online";
    else return "Cash";
}

std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
    os << "_invoiceNumber: " << rhs._invoiceNumber
       << " _amount: " << rhs._amount
       << " _type: " << displayType(rhs._type);
    return os;
}

Invoice::Invoice(std::string inNum, float amount, PaymentType type)
    : _invoiceNumber{inNum}, _amount{amount},_type{type}{}