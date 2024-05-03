#include "ConfirmedTrip.h"
std::ostream &operator<<(std::ostream &os, const ConfirmedTrip &rhs) {
    os << static_cast<const TravelTrip &>(rhs)
       << "\nCcarType: " << displayType(rhs._carType)
       << "\nTraffic: " << displayTraffic(rhs._traffic);
    return os;
}

str displayTraffic(TrafficState t)
{
    str traffic;
    if(t==TrafficState::HEAVY) traffic="HEAVY";
    else if(t==TrafficState::LIGHT) traffic="LIGHT";
    else traffic="Moderate";
    return traffic;
}

str displayType(CarType t)
{
    str type;
    if(t==CarType::BASIC) type="Basic";
    else if(t==CarType::NEO) type="Neo";
    else type="Prime";
    return type;
}

ConfirmedTrip::ConfirmedTrip(str start, str destination, float distance, CarType type, TrafficState traffic)
    : TravelTrip(start,destination,distance), _carType{type}, _traffic{traffic}
{}

float ConfirmedTrip::totalTravelFair()
{
    float fair{0};
    if(this->carType() == CarType::BASIC)
        fair = distance()*1.2;
    else if(this->carType()==CarType::NEO)
        fair = distance()*1.5;
    else   
        fair = distance()*1.8;
    return fair;
}

float ConfirmedTrip::totalTripTravlTime()
{
    if(carType()==CarType::BASIC)
        return distance()*1.2+10;
    else if(carType()==CarType::NEO)
        return distance()*1.5+20;
    else
        return distance()*1.8+30;
}
