#ifndef CABBOOKING_H
#define CABBOOKING_H

#include <iostream>
class CabBooking
{
private:
    std::string _id;
    std::string _drop;
    std::string _pickup;
    float _baseFair;

public:
    // default constructor disabled
    CabBooking() = delete;
    // default copy constructor disabled
    CabBooking(const CabBooking &) = delete;
    // default move constructor disabled
    CabBooking(const CabBooking &&) = delete;
    // default assignment operator disabled
    CabBooking &operator=(const CabBooking &) = delete;
    // default move operator disabled
    CabBooking &operator=(const CabBooking &&) = delete;
    // default distructor enabled
    ~CabBooking() = default;

    CabBooking(std::string id, std::string drop, std::string pickup, float fair);

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string drop() const { return _drop; }
    void setDrop(const std::string &drop) { _drop = drop; }

    std::string pickup() const { return _pickup; }
    void setPickup(const std::string &pickup) { _pickup = pickup; }

    virtual float calculateFair() = 0;

    float baseFair() const { return _baseFair; }

    friend std::ostream &operator<<(std::ostream &os, const CabBooking &rhs);
};

#endif // CABBOOKING_H
