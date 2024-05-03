#ifndef PERMIT_H
#define PERMIT_H

#include<iostream>
#include "PermitType.h"

class Permit
{
private:
    std::string _serialNumer;
    PermitType _permitType;
    int _validityLeft;
    float _renewalCharge;
    
public:
    //default constructor disabled
    Permit()=delete;
    //default copy constructor disabled
    Permit(const Permit&) = delete;
    // default move constructor disabled 
    Permit(const Permit&&) = delete;
    // default assignment operator disabled 
    Permit &operator=(const Permit&) = delete; 
    // default move operator disabled
    Permit &operator=(const Permit&&) = delete; 
    // default distructor enabled 
    ~Permit()=default;

    Permit(std::string srNo, PermitType type, int dueration, float charge);

    std::string serialNumer() const { return _serialNumer; }
    void setSerialNumer(const std::string &serialNumer) { _serialNumer = serialNumer; }

    PermitType permitType() const { return _permitType; }
    void setPermitType(const PermitType &permitType) { _permitType = permitType; }

    int validityLeft() const { return _validityLeft; }
    void setValidityLeft(int validityLeft) { _validityLeft = validityLeft; }

    float renewalCharge() const { return _renewalCharge; }
    void setRenewalCharge(float renewalCharge) { _renewalCharge = renewalCharge; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};
std::string displayPermitType(PermitType t);

#endif // PERMIT_H
