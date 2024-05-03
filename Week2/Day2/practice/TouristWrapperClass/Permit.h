#ifndef PERMIT_H
#define PERMIT_H

#include<iostream>
#include "PermitType.h"

class Permit
{
private:
    std::string _serialNumber;
    PermitType _permitType;
    int _validityLeft;
    
public:
    //default constructor disabled
    Permit()=default;
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

    Permit(std::string srNo, PermitType type, int dueration);

    std::string serialNumer() const { return _serialNumber; }
    void setSerialNumer(const std::string &serialNumer) { _serialNumber = serialNumer; }

    PermitType permitType() const { return _permitType; }
    void setPermitType(const PermitType &permitType) { _permitType = permitType; }

    int validityLeft() const { return _validityLeft; }
    void setValidityLeft(int validityLeft) { _validityLeft = validityLeft; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};
std::string displayPermitType(PermitType t);

#endif // PERMIT_H
