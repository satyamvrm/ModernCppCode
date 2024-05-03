#include "Bill.h"
std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "_billNumber: " << rhs._billNumber
       << " _invoice: " << rhs._invoice;
    return os;
}

Bill::Bill(int billNum, std::reference_wrapper<Invoice> invoice) : _billNumber{billNum}, _invoice{invoice}
{}