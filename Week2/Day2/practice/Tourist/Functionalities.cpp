#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6726",
            VehicleType::BIKE,
            2,
            1500,
            std::make_shared<Permit>(
                "s101",
                PermitType::OWNED,
                60)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6776",
            VehicleType::BUS,
            12,
            35000,
            std::make_shared<Permit>(
                "s102",
                PermitType::LEASE,
                160)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SR6726",
            VehicleType::CAB,
            4,
            15000,
            std::make_shared<Permit>(
                "s103",
                PermitType::OWNED,
                180)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6726",
            VehicleType::BIKE,
            2,
            1500,
            std::make_shared<Permit>(
                "s101",
                PermitType::OWNED,
                60)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6776",
            VehicleType::BUS,
            12,
            35000,
            std::make_shared<Permit>(
                "s102",
                PermitType::LEASE,
                160)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SR6726",
            VehicleType::CAB,
            4,
            15000,
            std::make_shared<Permit>(
                "s103",
                PermitType::OWNED,
                180)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6726",
            VehicleType::BIKE,
            2,
            1500,
            std::make_shared<Permit>(
                "s101",
                PermitType::OWNED,
                60)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6776",
            VehicleType::BUS,
            12,
            35000,
            std::make_shared<Permit>(
                "s102",
                PermitType::LEASE,
                160)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SR6726",
            VehicleType::CAB,
            4,
            15000,
            std::make_shared<Permit>(
                "s103",
                PermitType::OWNED,
                180)));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw EmptyData("Data is Empty !\n");
    for (Vehicle c : data)
    {
        std::cout << *c << '\n';
    }
}

Container firstNInstanceOfTouristWithCondition(Container &data, int n)
{
    Container newData;
    if(data.empty()) throw EmptyData("Data is Empty ! ");
    if(n<0 || n>data.size()) throw EmptyData("Invalid no of instances ! ");
    for(auto c : data){
        if(c->noOfSeats()>3 && c->permit()->permitType()==PermitType::LEASE && n>0) {newData.push_back(c);n--;};
    }
    return newData;
}

float avgBookingCharges(Container &data, VehicleType t)
{
    float sum{0};
    if(data.empty()) throw EmptyData("Data is Empty ! ");
    // if(t!=VehicleType::BIKE || t!=VehicleType::BUS || t!=VehicleType::CAB) throw EmptyData("Invalid type of instance ! ");
    for(auto c : data){
        if(c->type()==t) sum+=c->perHourBookingCharges();
    }
    return sum/data.size();
}

std::string maxBookingCharges(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty ! ");
    float max = 0;
    std::string ans;
    for(auto c : data){
        if(c->perHourBookingCharges()>max) max = c->perHourBookingCharges();
    }
    for(auto c : data){
        if(c->perHourBookingCharges()==max) ans = c->permit()->serialNumer();
    }
    return ans;
    
}

Container firstNInstance(Container &data, int n)
{
    Container newData;
    if(data.empty()) throw EmptyData("Data is Empty ! ");
    if(n<0 || n>data.size()) throw EmptyData("Invalid no of instances ! ");
    for(auto c : data){
        if(n>0){
            newData.push_back(c);
            n--;
        } 
    }
    return newData;
    
}
