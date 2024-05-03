#include "CustomerAccount.h"

CustomerAccount::CustomerAccount(std::string name, std::string fname, Gender gType) : Account(name), _fullName{fname}, _customerGender{gType}
{
}

std::ostream &operator<<(std::ostream &os, const CustomerAccount &rhs) {
    std::string val{""};
    if(rhs._customerGender == Gender::MALE) val = "Male";
    else if(rhs._customerGender == Gender::FEMALE) val = "Female" ;
    else val = "Other";
    os << static_cast<const Account &>(rhs)
       << " _fullName: " << rhs._fullName
       << " _customerGender: " << val;
    return os;
}

void CustomerAccount::RegisterAccount()
{
    std::cout<<"Account verified via otp";
}
