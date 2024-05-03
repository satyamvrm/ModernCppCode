#include "Functionalities.h"

void createObjects(ContainerV &data1, ContainerP &data2)
{
    data2.push_back(std::make_shared<Permit>("p101", PermitType::LEASE, 13));
    data2.push_back(std::make_shared<Permit>("p102", PermitType::LEASE, 3));
    data2.push_back(std::make_shared<Permit>("p103", PermitType::OWNED, 1));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-1", VehicleType::BIKE, 2, 5000, *data2[0]));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-2", VehicleType::BIKE, 2, 5000, *data2[1]));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-3", VehicleType::CAB, 4, 15000, *data2[0]));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-4", VehicleType::CAB, 5, 15000, *data2[2]));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-5", VehicleType::BUS, 12, 35000, *data2[1]));
    data1.push_back(std::make_shared<TouristVehicle>("vehicle-6", VehicleType::BUS, 12, 53000, *data2[2]));
}

void displayObjects(ContainerV &data1, ContainerP &data2)
{
    if (data1.empty())
        std::cout << "NO Vehicle\n";
    if (data2.empty())
        std::cout << "NO Permit\n";
    for (auto c : data1)
        std::cout << *c << "\n";
    for (auto c : data2)
        std::cout << *c << "\n";
}

void deleteVehicle(ContainerV &data, int n)
{
    if (data.empty())
        std::cout << "NO Vehicle\n";
    data.clear();
}

void deletePermit(ContainerP &data)
{
    if (data.empty())
        std::cout << "NO Vehicle\n";
    delete[] &data;
    data.clear();
}

ContainerV firstNInstanceOfTouristWithCondition(ContainerV &data, int n)
{
    ContainerV newData;
    if (data.empty())
        throw EmptyData("Data is Empty ! ");
    if (n < 0 || n > data.size())
        throw EmptyData("Invalid no of instances ! ");
    for (auto c : data)
    {
        if (c->noOfSeats() > 3)
        {
            newData.push_back(c);
            n--;
        };
    }
    return newData;
}

float avgBookingCharges(ContainerV &data, VehicleType t)
{
    float sum{0};
    if (data.empty())
        throw EmptyData("Data is Empty ! ");
    // if(t!=VehicleType::BIKE || t!=VehicleType::BUS || t!=VehicleType::CAB) throw EmptyData("Invalid type of instance ! ");
    for (auto c : data)
    {
        if (c->type() == t)
            sum += c->perHourBookingCharges();
    }
    return sum / data.size();
}

// std::string maxBookingCharges(ContainerV &data)
// {
//     if(data.empty()) throw EmptyData("Data is Empty ! ");
//     float max = 0;
//     std::shared_ptr<Permit> ans;
//     for(auto c : data){
//         if(c->perHourBookingCharges()>max) max = c->perHourBookingCharges();
//     }

//     for(auto c : data){
//         if(c->perHourBookingCharges()==max) ans = c->permit() ;
//     }
//     return ans;

// }

ContainerV firstNInstance(ContainerV &data, int n)
{
    ContainerV newData;
    if (data.empty())
        throw EmptyData("Data is Empty ! ");
    if (n < 0 || n > data.size())
        throw EmptyData("Invalid no of instances ! ");
    for (auto c : data)
    {
        if (n > 0)
        {
            newData.push_back(c);
            n--;
        }
    }
    return newData;
}
