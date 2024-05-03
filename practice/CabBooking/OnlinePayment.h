#ifndef ONLINEPAYMENT_H
#define ONLINEPAYMENT_H

#include "PaymentType.h"
#include "CabBooking.h"
#include <ostream>

class OnlinePayment : public CabBooking
{
private:
    PaymentType _type;
    int _dropCount;

public:
    //default constructor disabled
    OnlinePayment()=delete;
    //default copy constructor disabled
    OnlinePayment(const OnlinePayment&) = delete;
    // default move constructor disabled 
    OnlinePayment(const OnlinePayment&&) = delete;
    // default assignment operator disabled 
    OnlinePayment &operator=(const OnlinePayment&) = delete; 
    // default move operator disabled
    OnlinePayment &operator=(const OnlinePayment&&) = delete; 
    // default distructor enabled 
    ~OnlinePayment()=default;

    OnlinePayment(std::string id, std::string drop, std::string start, float fair, PaymentType type, int count);

    friend std::ostream &operator<<(std::ostream &os, const OnlinePayment &rhs);

    float calculateFair() override;

    PaymentType type() const { return _type; }
    void setType(const PaymentType &type) { _type = type; }

    int dropCount() const { return _dropCount; }
    void setDropCount(int dropCount) { _dropCount = dropCount; }

};
#endif // ONLINEPAYMENT_H
