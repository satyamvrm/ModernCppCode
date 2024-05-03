#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "FlightType.h"

class Flight
{
private:
    std::string _flightId;
    int _seatCount;
    float _distance;
    FlightType _type;
    
public:
    //default constructor disabled
    Flight()=delete;
    //default copy constructor disabled
    Flight(const Flight&) = default;
    // default move constructor disabled 
    Flight(const Flight&&) = delete;
    // default assignment operator disabled 
    Flight &operator=(const Flight&) = default; 
    // default move operator disabled
    Flight &operator=(const Flight&&) = delete; 
    // default distructor enabled 
    ~Flight()=default;

    Flight(std::string id, int seats, float distance, FlightType type);

    std::string flightId() const { return _flightId; }
    void setFlightId(const std::string &flightId) { _flightId = flightId; }

    int seatCount() const { return _seatCount; }
    void setSeatCount(int seatCount) { _seatCount = seatCount; }

    float distance() const { return _distance; }
    void setDistance(float distance) { _distance = distance; }

    FlightType type() const { return _type; }
    void setType(const FlightType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);

    
    
};

#endif // FLIGHT_H
