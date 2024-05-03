#include "Account.h"
// std::ostream &operator<<(std::ostream &os, const Account &rhs)
// {
//     os << "_accNo: " << rhs._accNo
//        << " _balance: " << rhs._balance
//        << " _holderName: " << rhs._holderName;
//     return os;
// }

Account::Account(std::string accNo, float balance, std::string holderName, std::shared_ptr<DebitCard> debitCard)
    : _accNo{accNo},
      _balance{balance},
      _holderName{holderName},
      _debitCard{debitCard}

{
}
std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "_accNo: " << rhs._accNo
       << " _balance: " << rhs._balance
       << " _holderName: " << rhs._holderName;
    return os;
}
