#include "CashPayment.h"

CashPayment::CashPayment(std::string id, std::string drop, std::string start, float fair, int rewardpoint)
    : CabBooking(id,drop,start,fair), _rewardPoints{rewardpoint}
{
}

float CashPayment::calculateFair()
{
    if(rewardPoints()<baseFair()*0.25) return 2*baseFair();
    else return 1.5*baseFair() ;
}

std::ostream &operator<<(std::ostream &os, const CashPayment &rhs) {
    os << static_cast<const CabBooking &>(rhs)
       << "\nrewardPoints: " << rhs._rewardPoints;
    return os;
}
