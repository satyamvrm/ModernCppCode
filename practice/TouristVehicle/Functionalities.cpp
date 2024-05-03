#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6726",
            VehicleType::BIKE,
            2,
            std::make_shared<Permit>(
                "s101",
                PermitType::OWNED,
                60,
                1500
            )
        )
    );
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SL6776",
            VehicleType::BUS,
            12,
            std::make_shared<Permit>(
                "s102",
                PermitType::LEASE,
                160,
                35000
            )
        )
    );
    data.push_back(
        std::make_shared<TouristVehicle>(
            "RJ04SR6726",
            VehicleType::CAB,
            4,
            std::make_shared<Permit>(
                "s103",
                PermitType::OWNED,
                180,
                15000
            )
        )
    );
}

void displayObjects(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty !\n");
    for(Vehicle c : data){
        std::cout<<*c<<'\n';
    }
}

float AverageDuration(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty!\n");
    float average{0.0}, count{0.0};
    for(Vehicle c : data){
        if(c->type()==VehicleType::CAB){
            average+=c->permit()->validityLeft();
            count++;
        }
    }
    return average/count;
}

Container nInstance(Container &data, int n)
{
    if(data.empty()) throw EmptyData("Data is Empty");
    if(n<=0 || n>=data.size()) throw EmptyData("N is out of range");
    int count{0};
    Container newData;
    for(Vehicle c : data){
        if(count>=n) break;
        newData.push_back(c);
        count++;
    }
    return newData;
}

PermitType minimumRenualCharge(Container &data)
{
    if(data.empty()) throw EmptyData("Data is Empty");
    int min= float(INTMAX_MAX);
    for(Vehicle c : data){
        if(c->permit()->renewalCharge()<min) min = c->permit()->renewalCharge();
    }
    for(Vehicle c :data){
        if(c->permit()->renewalCharge()==min) return c->permit()->permitType();
    }
}
