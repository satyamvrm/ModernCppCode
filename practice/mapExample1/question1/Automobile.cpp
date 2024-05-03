#include "Automobile.h"

std::string displayType(AutomobileType t){
    if(AutomobileType::PRIVATE==t) return "Private";
    else return "Transport";
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "\nmodel_name: " << rhs._model_name
       << "\nautomobile_type: " << displayType(rhs._automobile_type)
       << "\nautomobile_value: " << rhs._automobile_price
       << "\nautomobile_mileage: " << rhs._automobile_mileage<<'\n';
    return os;
}

Automobile::Automobile(std::string name, AutomobileType type, float value, float milage)
    : _model_name{name}, _automobile_type{type}, _automobile_price{value},_automobile_mileage{milage}
{}