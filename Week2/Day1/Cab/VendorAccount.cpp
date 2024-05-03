#include "VendorAccount.h"

VendorAccount::VendorAccount(std::string name,std::string vName) : Account(name), _vendorName{vName}
{}

VendorAccount::VendorAccount(std::string name, std::string vName, const DriverContainer &driver, const CabUnitContainer &cabs) : VendorAccount(name,vName){
    _drivers = driver;
    _cabUnits = cabs;
}


void VendorAccount::RegisterAccount()
{
    std::cout<<"Vendor Verified as per government norms!";
}

std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " _vendorName: " << rhs._vendorName;
    return os;
}
