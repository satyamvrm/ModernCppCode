#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include<iostream>
using str = std::string;

class TravelTrip
{
private:
    str _startPoint;
    str _destinationPoint;
    float _distance;    
public:
    //default constructor disabled
    TravelTrip()=delete;
    //default copy constructor disabled
    TravelTrip(const TravelTrip&) = delete;
    // default move constructor disabled 
    TravelTrip(const TravelTrip&&) = delete;
    // default assignment operator disabled 
    TravelTrip &operator=(const TravelTrip&) = delete; 
    // default move operator disabled
    TravelTrip &operator=(const TravelTrip&&) = delete; 
    // default distructor enabled 
    ~TravelTrip()=default;

    TravelTrip(str start, str destination, float distance);

    virtual float totalTravelFair() = 0;
    virtual float totalTripTravlTime() = 0;

    str startPoint() const { return _startPoint; }
    void setStartPoint(const str &startPoint) { _startPoint = startPoint; }

    str destinationPoint() const { return _destinationPoint; }
    void setDestinationPoint(const str &destinationPoint) { _destinationPoint = destinationPoint; }

    float distance() const { return _distance; }
    void setDistance(float distance) { _distance = distance; }


    friend std::ostream &operator<<(std::ostream &os, const TravelTrip &rhs);
    

};

#endif // TRAVELPLAN_H
