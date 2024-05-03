#include "TouristVehicle.h"

std::string displayType(VehicleType t){
    if(t==VehicleType::BIKE) return "Bike";
    else if(t==VehicleType::BUS) return "Bus";
    else return "Cab";
}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "\nvehicleNumber: " << rhs._vehicleNumber
       << "\ntype: " << displayType(rhs._type)
       << "\nnoOfSeats: " << rhs._noOfSeats
       << "\npermit: " << *rhs._permit;
    return os;
}

TouristVehicle::TouristVehicle(std::string num, VehicleType type, int seat, Pointer ptr)
    : _vehicleNumber{num}, _type{type},_noOfSeats{seat}, _permit{ptr}
{}