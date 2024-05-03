#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
#include "DriverRating.h"

class Driver
{
private:
    std::string _id;
    DriverRating _rating;
public:
    //default constructor disabled
    Driver()=default;
    //default copy constructor disabled
    Driver(const Driver&) = delete;
    // default move constructor disabled 
    Driver(Driver&&) = default;
    // default assignment operator disabled 
    Driver &operator=(const Driver&) = delete; 
    // default move operator disabled
    Driver &operator=(const Driver&&) = delete; 
    // default distructor enabled 
    ~Driver()=default;

    DriverRating rating() const { return _rating; }
    void setRating(const DriverRating &rating) { _rating = rating; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    Driver(std::string id, DriverRating rating);

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};

#endif // DRIVER_H
