#ifndef VENDOR_H
#define VENDOR_H

#include "Account.h"
#include <ostream>
#include<vector>
#include "Driver.h"

using DriverContainer = std::vector<Driver*>;
using CabUnitContainer = std::vector<CabUnit*>;

class VendorAccount : public Account
{
private:
    /* data */
    std::string _vendorName;
    DriverContainer _drivers{};
    CabUnitContainer _cabUnits{};
    
public:
    VendorAccount()=delete;
    VendorAccount(const VendorAccount&)=delete;
    VendorAccount(const VendorAccount&&)=delete;
    VendorAccount &operator=(const VendorAccount&) = delete;
    VendorAccount &operator=(const VendorAccount&&) = delete;
    ~VendorAccount() = default;

    VendorAccount(std::string name, std::string vName);
    VendorAccount(std::string name, std::string vName,const DriverContainer& driver, const CabUnitContainer& cabs);
    void RegisterAccount() override;

    std::string vendorName() const { return _vendorName; }
    void setVendorName(const std::string &vendorName) { _vendorName = vendorName; }

    friend std::ostream &operator<<(std::ostream &os, const VendorAccount &rhs);
};

#endif // VENDOR_H
