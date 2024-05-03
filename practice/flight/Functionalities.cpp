#include "Functionalities.h"

void createObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<Flight>("f101", 55, 1020.0f, FlightType::Commercial));
    data.emplace_back(
        std::make_shared<Flight>("f102", 14, 1020.0f, FlightType::Private));
    data.emplace_back(
        std::make_shared<Flight>("f103", 5, 1030.0f, FlightType::Courier));
}

void displayObjects(Container &data)
{
    if (data.empty())
        throw std::runtime_error("Data is Empty");
    for (FlightPtr f : data)
    {
        std::cout << *f << '\n';
    }
}

void operations(Container &data, FunctionContainer &functions)
{
    if (data.empty() || functions.empty())
        throw std::runtime_error("Provieded list is empty");
    for (std::function<int(Container &)> fns : functions)
        std::cout<<fns(data)<<"\n";
}

std::function<int(Container&)> over50SeatsFlights = [](Container& data)
{
    if (data.empty())
        throw std::runtime_error("Data is Empty");
    int count{0};
    for(auto c : data){
        if(c->seatCount()>50){
            count++;
        }
    }
    return count;
};

std::function<std::string(Container&)> longestFlightDistace = [](Container& data)
{
    if (data.empty())
        throw std::runtime_error("Data is Empty");
    FlightPtr max = data.front();
    for (FlightPtr f : data)
    {
        if(f->distance()>max->distance()) max = f;  
    }
    return max->flightId();
};

std::function<float(Container&)> highestFlightSeats = [](Container& data){
    if (data.empty())
        throw std::runtime_error("Data is Empty");
    FlightPtr max = data.front();
    for (FlightPtr f : data)
    {
        if(f->seatCount()>max->seatCount()) max = f;  
    }
    return max->distance();
};

std::function<int(Container&)> highestEntries = [](Container& data){
    if (data.empty())
        throw std::runtime_error("Data is Empty");
    int count{0};
    for(auto c : data){
        count+=c->seatCount();
    }
    return count;
};
