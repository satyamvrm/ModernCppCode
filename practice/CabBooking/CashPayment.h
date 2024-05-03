#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "CabBooking.h"
#include <ostream>

class CashPayment : public CabBooking
{
private:
    int _rewardPoints;
public:
    //default constructor disabled
    CashPayment()=delete;
    //default copy constructor disabled
    CashPayment(const CashPayment&) = delete;
    // default move constructor disabled 
    CashPayment(const CashPayment&&) = delete;
    // default assignment operator disabled 
    CashPayment &operator=(const CashPayment&) = delete; 
    // default move operator disabled
    CashPayment &operator=(const CashPayment&&) = delete; 
    // default distructor enabled 
    ~CashPayment()=default;

    CashPayment(std::string id,std::string drop, std::string start, float fair, int rewardpoint);

    float calculateFair() override;

    int rewardPoints() const { return _rewardPoints; }
    void setRewardPoints(int rewardPoints) { _rewardPoints = rewardPoints; }

    friend std::ostream &operator<<(std::ostream &os, const CashPayment &rhs);
    
};

#endif // CASHPAYMENT_H
