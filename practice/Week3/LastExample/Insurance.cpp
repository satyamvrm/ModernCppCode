#include "Insurance.h"

std::string displayType(InsuranceType t){
    if(t==InsuranceType::Rgular) return "Rgular";
    else return "ZeroDebt";
}

std::ostream &operator<<(std::ostream &os, const Insurance &rhs) {
    os << "_id: " << rhs._id
       << " _amount: " << rhs._amount
       << " _type: " << displayType(rhs._type);
    return os;
}

Insurance::Insurance(std::string id, float amount, InsuranceType type)
    : _id{id}, _amount{amount}, _type{type}
{}