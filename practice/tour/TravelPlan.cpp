#include "TravelPlan.h"
std::ostream &operator<<(std::ostream &os, const TravelTrip &rhs) {
    os << "StartPoint: " << rhs._startPoint
       << "\nDestinationPoint: " << rhs._destinationPoint
       << "\nDistance: " << rhs._distance;
    return os;
}

TravelTrip::TravelTrip(str start, str destination, float distance)
: _startPoint{start}, _destinationPoint{destination}, _distance{distance}
{
}