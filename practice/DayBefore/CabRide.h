#ifndef CABRIDE_H
#define CABRIDE_H

#include "Driver.h"
#include "PaymentMode.h"
#include "RideType.h"
#include <variant>
#include <memory>
#include <functional>
#include <ostream>

class CabRide
{
private:
    std::variant<int,std::string> _id;
    RideType _rideType;
    PaymentMode _paymentMode;
    float _fair;
    std::string _pickup;
    std::string _drop;
    std::reference_wrapper<Driver> _driver;

public :
    // default constructor disabled
    CabRide() = delete;
    // default copy constructor disabled
    CabRide(const CabRide &) = delete;
    // default move constructor disabled
    CabRide(const CabRide &&) = delete;
    // default assignment operator disabled
    CabRide &operator=(const CabRide &) = delete;
    // default move operator disabled
    CabRide &operator=(const CabRide &&) = delete;
    // default distructor enabled
    ~CabRide() = default;

    CabRide(std::variant<int,std::string> id,RideType rideType,PaymentMode paymentMode,float fair,std::string pickup, std::string drop, std::reference_wrapper<Driver> driver);

    std::variant<int,std::string> id() const { return _id; }
    void setId(const std::variant<int,std::string> &id) { _id = id; }

    RideType rideType() const { return _rideType; }
    void setRideType(const RideType &rideType) { _rideType = rideType; }

    PaymentMode paymentMode() const { return _paymentMode; }
    void setPaymentMode(const PaymentMode &paymentMode) { _paymentMode = paymentMode; }

    float fair() const { return _fair; }
    void setFair(float fair) { _fair = fair; }

    std::string pickup() const { return _pickup; }
    void setPickup(const std::string &pickup) { _pickup = pickup; }

    std::string drop() const { return _drop; }
    void setDrop(const std::string &drop) { _drop = drop; }

    friend std::ostream &operator<<(std::ostream &os, const CabRide &rhs);
};

#endif // CABRIDE_H
