#ifndef CONFIRMEDTRIP_H
#define CONFIRMEDTRIP_H

#include "TrafficState.h"
#include "CarType.h"
#include "TravelPlan.h"
#include <ostream>

class ConfirmedTrip : public TravelTrip
{
private:
    CarType _carType;
    TrafficState _traffic;

public:
    //default constructor disabled
    ConfirmedTrip()=delete;
    //default copy constructor disabled
    ConfirmedTrip(const ConfirmedTrip&) = delete;
    // default move constructor disabled 
    ConfirmedTrip(const ConfirmedTrip&&) = delete;
    // default assignment operator disabled 
    ConfirmedTrip &operator=(const ConfirmedTrip&) = delete; 
    // default move operator disabled
    ConfirmedTrip &operator=(const ConfirmedTrip&&) = delete; 
    // default distructor enabled 
    ~ConfirmedTrip()=default;

    ConfirmedTrip(str start, str destination, float distance, CarType type, TrafficState traffic);

    float totalTravelFair() override;
    float totalTripTravlTime() override;

    CarType carType() const { return _carType; }
    void setCarType(const CarType &carType) { _carType = carType; }

    TrafficState traffic() const { return _traffic; }
    void setTraffic(const TrafficState &traffic) { _traffic = traffic; }

    friend std::ostream &operator<<(std::ostream &os, const ConfirmedTrip &rhs);
    
};
str displayTraffic(TrafficState t);
str displayType(CarType t);


#endif // CONFIRMEDTRIP_H