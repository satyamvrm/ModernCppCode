#include "CabRide.h"
std::ostream &operator<<(std::ostream &os, const CabRide &rhs)
{
    std::visit([&](auto&& arg){os<<arg;},rhs._id);
    os << " _rideType: " << static_cast<int>(rhs._rideType)
       << " _paymentMode: " << static_cast<int>(rhs._paymentMode)
       << " _fair: " << rhs._fair
       << " _pickup: " << rhs._pickup
       << " _drop: " << rhs._drop
       << " _driver: " << rhs._driver.get();
    return os;
}

CabRide::CabRide(std::variant<int, std::string> id, RideType rideType, PaymentMode paymentMode, float fair, std::string pickup, std::string drop, std::reference_wrapper<Driver> driver) : _id{id}, _rideType{rideType}, _paymentMode{paymentMode}, _fair{fair}, _pickup{pickup}, _drop{drop}, _driver{driver}
{
}