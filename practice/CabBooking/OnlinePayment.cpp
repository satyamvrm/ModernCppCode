#include "OnlinePayment.h"

std::string displayType(PaymentType t){
    if(t==PaymentType::UPI) return "UPI";
    if(t==PaymentType::WALLET) return "WALLET";
    else return "CARD";
}

std::ostream &operator<<(std::ostream &os, const OnlinePayment &rhs) {
    os << static_cast<const CabBooking &>(rhs)
       << "\ntype: " << displayType(rhs._type)
       << "\ndropCount: " << rhs._dropCount;
    return os;
}

OnlinePayment::OnlinePayment(std::string id, std::string drop, std::string start, float fair, PaymentType type, int count)
    : CabBooking(id,drop,start,fair), _type(type), _dropCount{count}
{}

float OnlinePayment::calculateFair()
{
    if(_type == PaymentType::CARD || _type==PaymentType::UPI) return baseFair()*dropCount();
    else return baseFair()+baseFair()*0.1;
}
