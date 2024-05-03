#include "Flight.h"

std::string displayType(FlightType t){
    if(t==FlightType::Commercial) return "Commercial";
    else if (t==FlightType::Courier) return "Courier";
    else return "Private";
}

std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_flightId: " << rhs._flightId
       << " _seatCount: " << rhs._seatCount
       << " _distance: " << rhs._distance
       << " _type: " << displayType(rhs._type);
    return os;
}

Flight::Flight(std::string id, int seats, float distance, FlightType type)
    : _flightId{id}, _seatCount{seats}, _distance{distance}, _type{type}
{}