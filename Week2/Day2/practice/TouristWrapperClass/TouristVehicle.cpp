#include "TouristVehicle.h"

std::string displayType(VehicleType t){
    if(t==VehicleType::BIKE) return "Bike";
    else if(t==VehicleType::BUS) return "Bus";
    else return "Cab";
}

TouristVehicle::TouristVehicle(std::string num, VehicleType type, int seat, float charges, std::reference_wrapper<Permit> pr)
    : _vehicleNumber{num}, _type{type},_noOfSeats{seat}, _perHourBookingCharges{charges}, _permit{pr}
{}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "\nvehicleNumber: " << rhs._vehicleNumber
       << "\ntype: " << displayType(rhs._type)
       << "\nnoOfSeats: " << rhs._noOfSeats
       << "\nperHourBookingCharges: " << rhs._perHourBookingCharges
       << "\npermit: " << rhs._permit.get();
    return os;
}
