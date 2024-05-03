#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(
        std::make_shared<ConfirmedTrip>(
            "Delhi",
            "Pune",
            1390.2f,
            CarType::PRIME,
            TrafficState::HEAVY
        )
    );
    data.push_back(
        std::make_shared<ConfirmedTrip>(
            "Banglore",
            "Pune",
            790.2f,
            CarType::NEO,
            TrafficState::MODERATE
        )
    );
    data.push_back(
        std::make_shared<ConfirmedTrip>(
            "Delhi",
            "Gorakhpur",
            1090.2f,
            CarType::BASIC,
            TrafficState::LIGHT
        )
    );
    data.push_back(
        std::make_shared<ConfirmedTrip>(
            "Mumbai",
            "Goa",
            890.2f,
            CarType::PRIME,
            TrafficState::HEAVY
        )
    );
}

void displayObjects(Container &data)
{
    for(std::shared_ptr<ConfirmedTrip> c : data)
        std::cout<<*c<<"\n\n";
}

float findAverageTravelTime(Container &data)
{
    float avg{0.0f}, count{0.0f};
    if(data.empty()) throw EmptyData("Data is empty :( \n");
    for(std::shared_ptr<ConfirmedTrip> c : data){
        avg += c->totalTripTravlTime();
        count++;
    }
    return avg/count;
}

float findMinimumTimeTravel(Container &data)
{
    float min=20000.0f;
    if(data.empty()) throw EmptyData("Data is Empty :(\n");
    for(std::shared_ptr<ConfirmedTrip> c : data){
        if(min>c->totalTripTravlTime())
            min=c->totalTripTravlTime();
    }
    return min;
}

int findCount(Container &data, CarType type)
{
    int count{0};
    if(data.empty()) throw EmptyData("Data is Empty :( \n");
    for(std::shared_ptr<ConfirmedTrip> c :data){
        if(c->carType()==type) count++;
    }
    return count;
}
