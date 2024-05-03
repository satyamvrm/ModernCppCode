#include "Permit.h"

std::string displayPermitType(PermitType t){
    if(t==PermitType::LEASE) return "Lease";
    else return "Owned";
}

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "\nserialNumer: " << rhs._serialNumber
       << "\npermitType: " << displayPermitType(rhs._permitType)
       << "\nvalidityLeft: " << rhs._validityLeft;
    return os;
}

Permit::Permit(std::string srNo, PermitType type, int dueration):
    _serialNumber{srNo}, _permitType{type}, _validityLeft{dueration}
{}