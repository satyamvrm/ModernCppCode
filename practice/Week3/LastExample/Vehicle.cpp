#include "Vehicle.h"

std::string displayVehicle(VehicleType t){
    if(t==VehicleType::Commercial) return "Commercial";
    else if(t==VehicleType::Private) return "Private";
    else return "Transport";
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os<<"_registrationId : ";
    std::visit(
        [](auto && args){std::cout<<args;},rhs.registrationId()
    );
    os   << " _reistrationNo: " << rhs._reistrationNo
       << " _type: " << displayVehicle(rhs._type)
       << " _insurance: " << rhs._insurance;
    return os;
}

Vehicle::Vehicle(std::variant<int, std::string> id, int reg, VehicleType type, std::reference_wrapper<Insurance> insurance)
    : _registrationId{std::move(id)}, _reistrationNo{reg}, _type{type}, _insurance{insurance}{}