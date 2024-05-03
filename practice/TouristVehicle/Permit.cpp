#include "Permit.h"

std::string displayPermitType(PermitType t){
    if(t==PermitType::LEASE) return "Lease";
    else return "Owned";
}

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "\nserialNumer: " << rhs._serialNumer
       << "\npermitType: " << displayPermitType(rhs._permitType)
       << "\nvalidityLeft: " << rhs._validityLeft
       << "\nrenewalCharge: " << rhs._renewalCharge;
    return os;
}

Permit::Permit(std::string srNo, PermitType type, int dueration, float charge):
    _serialNumer{srNo}, _permitType{type}, _validityLeft{dueration}, _renewalCharge{charge}
{}