#ifndef INSURANCE_H
#define INSURANCE_H

#include "InsuranceType.h"
#include<iostream>

class Insurance
{
private:
    std::string _id;
    float _amount;
    InsuranceType _type;

public:
    //default constructor disabled
    Insurance()=delete;
    //default copy constructor disabled
    Insurance(const Insurance&) = delete;
    // default move constructor disabled 
    Insurance(const Insurance&&) = delete;
    // default assignment operator disabled 
    Insurance &operator=(const Insurance&) = delete; 
    // default move operator disabled
    Insurance &operator=(const Insurance&&) = delete; 
    // default distructor enabled 
    ~Insurance()=default;

    Insurance(std::string id, float amount, InsuranceType type);

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float amount() const { return _amount; }
    void setAmount(float amount) { _amount = amount; }

    InsuranceType type() const { return _type; }
    void setType(const InsuranceType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Insurance &rhs);    
};
std::string displayType(InsuranceType t);
#endif // INSURANCE_H
