#include "CabBooking.h"
std::ostream &operator<<(std::ostream &os, const CabBooking &rhs) {
    os << "\nid: " << rhs._id
       << "\ndrop: " << rhs._drop
       << "\npickup: " << rhs._pickup
       << "\nbaseFair: " << rhs._baseFair;
    return os;
}

CabBooking::CabBooking(std::string id, std::string drop, std::string pickup, float fair)
    : _id{id}, _drop{drop}, _pickup{pickup}, _baseFair{fair}
{
}