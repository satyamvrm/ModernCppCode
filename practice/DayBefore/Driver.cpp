#include "Driver.h"
std::ostream &operator<<(std::ostream &os, const Driver &rhs)
{
    os << "_id: " << rhs._id
       << " _rating: " << static_cast<int>(rhs._rating);
    return os;
}

Driver::Driver(std::string id, DriverRating rating) : _id{id}, _rating{rating} {}